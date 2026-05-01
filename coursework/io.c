//
// Created by loran on 10/04/2026.
//

#include "io.h"

#include <stdlib.h>


int fetchSamples(void) {
// load csv file into struct array

// Open a file in read mode
    FILE* fptr = fopen("power_quality_log.csv", "r");

    // If the file is empty
    if(fptr == NULL) {
        printf("Not able to open the file.");
        return 1;
        // quit function with error code
    }
    waveformSample *samples; //Set up array of samples
    size_t count;
    size_t capacity = 4;

    char line[256]; //buffer to store each line
    while (fgets(line, sizeof(line), fptr)){
        if (count >= capacity)
        {
            capacity *= 2;

            //if realloc fails, we risk losing our pointer so we use a buffer and check to prevent this
            waveformSample *buffer = realloc(samples, sizeof(waveformSample) * capacity);
            if (buffer == NULL)
            {
                printf("Not able to reallocate memory.");
                fclose(fptr);
                return 1;
            }
            samples = buffer;
            //add parsing + validation(include check for clipping)
        }

    }



    // Close the file
    fclose(fptr);
    return 0;
}
