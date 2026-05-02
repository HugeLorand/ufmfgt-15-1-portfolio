//
// Created by loran on 10/04/2026.
//

#include "io.h"

#include <stdlib.h>



void fetchSamples(waveformSample **samples, size_t *count)
{
    FILE *fptr = fopen("power_quality_log.csv", "r");
    if (fptr == NULL) {
        perror("Failed to open file");
        return;
    }

    *samples = NULL;
    size_t capacity = 32;
    *count = 0; // size_t type allows safe large mallocs without risk of overflow
    *samples = malloc(sizeof(waveformSample) * capacity);

    if (*samples == NULL) {
        perror("Initial allocation failed");
        fclose(fptr);
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fptr))
    {

        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (line[0] == '\0') {
            continue;
        }


        //realloc if more space needed
        if (*count >= capacity)
        {
            capacity *= 2;

            //if realloc fails, we risk losing our pointer so we use a buffer and check to prevent this
            waveformSample *buffer = realloc(*samples, sizeof(waveformSample) * capacity);
            if (buffer == NULL)
            {
                printf("Not able to reallocate memory.");
                free(samples);
                fclose(fptr);
                return;
            }
            *samples = buffer;
        }
        //parse values to struct

        waveformSample *sample = &(*samples)[*count];
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &sample->values[0],
            &sample->values[1],
            &sample->values[2],
            &sample->values[3],
            &sample->values[4],
            &sample->values[5],
            &sample->values[6],
            &sample->values[7]);
        samples[*count] = sample;
        (*count)++;
    }



    // Close the file
    fclose(fptr);
    }


