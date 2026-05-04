//
// Created by loran on 10/04/2026.
//

#ifndef COURSEWORK_IO_H
#define COURSEWORK_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"




void fetchSamples(waveformSample **samples, size_t *count);
int validate_sample(waveformSample*);
int parse_line(char*, waveformSample*);
void output(FILE *out, v_results aRes, v_results bRes, v_results cRes, int clipped);
int report();


#endif //COURSEWORK_IO_H

