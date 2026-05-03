//
// Created by loran on 10/04/2026.
//

#ifndef COURSEWORK_IO_H
#define COURSEWORK_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "waveform.h"


typedef struct
{
    double values[8];
} waveformSample;

typedef enum
{
    time,
    va,
    vb,
    vc,
    lineCurrent,
    freq,
    pf,
    thd
} wave;


typedef struct {
    waveformSample *data;
    size_t size;
} sampleArray;


void fetchSamples(waveformSample **samples, size_t *count);
int validate_sample(waveformSample*);
int parse_line(char*, waveformSample*);
void output(FILE *out, v_results aRes, v_results bRes, v_results cRes, int clipped);
int report();


#endif //COURSEWORK_IO_H

