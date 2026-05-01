//
// Created by loran on 10/04/2026.
//

#include "io.h"

#include <stdlib.h>


sampleArray fetchSamples(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Failed to open file");
        return (sampleArray){NULL, 0};
    }

    waveformSample *samples = NULL;
    size_t count = 0;
    size_t capacity = 4;

    samples = malloc(sizeof(waveformSample) * capacity);
    if (samples == NULL) {
        perror("Initial allocation failed");
        fclose(fptr);
        return (sampleArray){NULL, 0};
    }

    char line[256];
    size_t line_number = 0;

    while (fgets(line, sizeof(line), fptr))
    {
        line_number++;

        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (line[0] == '\0') {
            continue;
        }

        waveformSample sample;

        if (!parse_line(line, &sample)) {
            fprintf(stderr, "Malformed line %zu: %s\n", line_number, line);
            continue;
        }

        if (!validate_sample(&sample))
        {
            fprintf(stderr, "Invalid data at line %zu: %s\n", line_number, line);
            continue;
        }
        //realloc if more space needed
        if (count >= capacity)
        {
            capacity *= 2;

            //if realloc fails, we risk losing our pointer so we use a buffer and check to prevent this
            waveformSample *buffer = realloc(samples, sizeof(waveformSample) * capacity);
            if (buffer == NULL)
            {
                printf("Not able to reallocate memory.");
                free(samples);
                fclose(fptr);
                return (sampleArray){NULL, 0};
            }
            samples = buffer;
        }
        samples[count] = sample;
        count++;
    }



    // Close the file
    fclose(fptr);
    return (sampleArray){samples, count};
    }


    //function to parse values to struct
    int parse_line(char *line, waveformSample *out)
    {
        return sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &out->values[0],
            &out->values[1],
            &out->values[2],
            &out->values[3],
            &out->values[4],
            &out->values[5],
            &out->values[6],
            &out->values[7]
            );
    }

    int validate_samples(const waveformSample *s)
    {
        // Example ranges — customize these
        static const double min_vals[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        static const double max_vals[8] = {2, 350, 350, 350, 1000, 1000, 1000, 1000}; //change these values

        for (int i = 0; i < 8; i++) {
            double v = s->values[i];

            if (!isfinite(v)) {
                return 0;
            }

            if (v < min_vals[i] || v > max_vals[i]) {
                return 0;
            }
        }

        return 1;
    }