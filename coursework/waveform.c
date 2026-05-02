//
// Created by loran on 10/04/2026.
//

#include "waveform.h"


int analyse()
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
        r = values[i];
        double vA = r.values[va];
        double vB = r.values[vb];
        double vC = r.values[vc];

        vA_total_sqrd += vA * vA;
        vB_total_sqrd_B += vB * vB;
        vB_total_sqrd += vC * vC;
        vA_total_v  += vA;
        vB_total_v  += vB;
        vC_total_v  += vC;

        if (vA > vA_max) vA_max = vA;
        if (vA < vA_min) vA_min = vA;
        if (vB > vB_max) vB_max = vB;
        if (vB < vB_min) vB_min = vB;
        if (vC > vC_max) vC_max = vC;
        if (vC < vC_min) vC_min = vC;

        if (fabs(vA) >= 324.9 || fabs(vB) >= 324.9 || fabs(vC) >= 324.9) clipped++;

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