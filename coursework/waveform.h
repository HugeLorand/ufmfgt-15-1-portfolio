//
// Created by loran on 10/04/2026.
//

#ifndef COURSEWORK_WAVEFORM_H
#define COURSEWORK_WAVEFORM_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "types.h"


int calc(char *in, FILE *out);
v_results phase_calc(waveformSample *samples, size_t count, int choice);
#endif //COURSEWORK_WAVEFORM_H
