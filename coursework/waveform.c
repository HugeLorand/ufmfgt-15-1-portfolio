//
// Created by loran on 10/04/2026.
//

#include "waveform.h"


int analyse(FILE *out1, FILE *out2)
{
    waveformSample *values = NULL;
    int count = 0;
    fetchSamples(&values, &count);

    if (values == NULL || count == 0) {
        printf("No valid records found.\n");
        free(values);
        return 1;
    }
    //to add: loads ofmaths

}