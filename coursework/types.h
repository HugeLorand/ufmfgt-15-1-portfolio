//
// Created by loran on 04/05/2026.
//

#ifndef COURSEWORK_TYPES_H
#define COURSEWORK_TYPES_H

typedef struct WaveformSample
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

typedef struct
{
    double rms;
    double peak_peak;
    double offset;
    int clipped;
} v_results;

#endif //COURSEWORK_TYPES_H
