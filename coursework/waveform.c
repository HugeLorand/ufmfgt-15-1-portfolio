//
// Created by loran on 10/04/2026.
//

#include "waveform.h"


int analyse(char *filein, char * fileout)
{
    waveformSample *values = NULL;
    size_t count = 0;
    fetchSamples(&values, &count);

    if (values == NULL || count == 0) {
        printf("No valid records found.\n");
        free(values);
        return 1;
    }
    double vA_total_sqrd = 0.0, vB_total_sqrd_B = 0.0, vB_total_sqrd = 0.0;
    double vA_total_v  = 0.0, vB_total_v  = 0.0, vC_total_v  = 0.0;
    double vA_max, vA_min, vB_max, vB_min, vC_max, vC_min;
    double freq_min, freq_max, pf_min, pf_max, thd_min, thd_max;
    int clipped = 0;

    waveformSample r = values[0];
    vA_max = vA_min  = r.values[va];
    vB_max = vB_min = r.values[vb];
    vC_max = vC_min = r.values[vc];
    freq_min = freq_max = r.values[freq];
    pf_min   = pf_max   = r.values[pf];
    thd_min  = thd_max  = r.values[thd];

    for (int i = 0; i < count; i++) {
        if (r.values[freq]    < freq_min) freq_min = r.values[freq];
        if (r.values[freq]    > freq_max) freq_max = r.values[freq];
        if (r.values[pf] < pf_min)   pf_min   = r.values[pf];
        if (r.values[pf] > pf_max)   pf_max   = r.values[pf];
        if (r.values[thd]  < thd_min)  thd_min  = r.values[thd];
        if (r.values[thd]  > thd_max)  thd_max  = r.values[thd];


    }
        /*
        phase_calc(samples, count, choice);
        check_freq(samples, count, nominal);
        read and report pf
        read and report thd

              |optional|
        sort samples by voltage
        */
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
    results.offset  = v_total;
    results.rms = sqrt(v_total_sqrd);
    return results;
}