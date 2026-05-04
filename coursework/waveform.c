//
// Created by loran on 10/04/2026.
//

#include "io.h"
#include "waveform.h"


int calc(char *filein, FILE *fileout)
{
    waveformSample *values = NULL;
    size_t count = 0;
    fetchSamples(&values, &count);

    if (values == NULL || count == 0) {
        printf("No valid records found.\n");
        free(values);
        return 1;
    }

    v_results a,b,c;
    a = phase_calc(values, count, 1);
    b = phase_calc(values, count, 2);
    c = phase_calc(values, count, 3);
    int clippedTotal = a.clipped + b.clipped + c.clipped;

    double freq_min, freq_max, pf_min, pf_max, thd_min, thd_max;


    waveformSample i = values[0];
    freq_min = freq_max = i.values[freq];
    pf_min   = pf_max   = i.values[pf];
    thd_min  = thd_max  = i.values[thd];
    double freq_total = 0.0;

    waveformSample *end = values + count;

    for (waveformSample *p = values; p < end; p++) {
        freq_total += p->values[freq];
        if (p->values[freq] < freq_min) freq_min = p->values[freq];
        if (p->values[freq] > freq_max) freq_max = p->values[freq];

        if (p->values[pf] < pf_min) pf_min = p->values[pf];
        if (p->values[pf] > pf_max) pf_max = p->values[pf];

        if (p->values[thd] < thd_min) thd_min = p->values[thd];
        if (p->values[thd] > thd_max) thd_max = p->values[thd];

    }
    double freq_mean = freq_total / count;
    free(values);

    output(fileout,a,b,c,freq_min,freq_max,freq_mean,thd_min,thd_max,pf_min,pf_max,thd_min,thd_max,clippedTotal);
    return 0;
}

v_results phase_calc(waveformSample *samples, size_t count, int choice)
{
    v_results results;
    int clipped = 0;
    double v, v_total, v_total_sqrd, v_min, v_max;
    v = v_total_sqrd = v_total = v_min = v_max = 0.0;
    for (int i = 0; i < count; i++)
    {
        v = samples[i].values[choice];
        if (v > v_max) v_max = v;
        if (v < v_min) v_min = v;
        if (fabs(v) >= 324.9)
        {
            clipped++;
        }
        v_total += v;
        v_total_sqrd += v * v;


    }
    results.clipped = clipped;
    results.peak_peak = v_max - v_min;
    results.offset  = v_total/count;
    results.rms = sqrt(v_total_sqrd/count);
    return results;
}