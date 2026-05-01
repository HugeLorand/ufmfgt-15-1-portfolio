//
// Created by loran on 10/04/2026.
//

#ifndef COURSEWORK_IO_H
#define COURSEWORK_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct
{
    double values[8];
} waveformSample;


typedef struct {
    waveformSample *data;
    size_t size;
} sampleArray;


sampleArray fetchSamples(char*);
int validate_sample(waveformSample*);
int parse_line(char*, waveformSample*);

#endif //COURSEWORK_IO_H

