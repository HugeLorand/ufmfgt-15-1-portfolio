//
// Created by loran on 10/04/2026.
//

#include "io.h"
#include "waveform.h"


void fetchSamples(const char *filename, waveformSample **samples, size_t *count)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), fptr); // skips header row

    *samples = NULL;
    size_t capacity = 32;
    *count = 0; // size_t type allows safe large mallocs without risk of overflow
    *samples = malloc(sizeof(waveformSample) * capacity);

    if (*samples == NULL) {
        perror("Initial allocation failed");
        fclose(fptr);
        return;
    }


    while (fgets(line, sizeof(line), fptr))
    {

        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (line[0] == '\0') {
            continue;
        }


        //realloc if more space needed
        if (*count >= capacity)
        {
            capacity *= 2;

            //if realloc fails, we risk losing our pointer so we use a buffer and check to prevent this
            waveformSample *buffer = realloc(*samples, sizeof(waveformSample) * capacity);
            if (buffer == NULL)
            {
                printf("Not able to reallocate memory.");
                free(*samples);
                fclose(fptr);
                return;
            }
            *samples = buffer;
        }
        //parse values to struct

        waveformSample *sample = &(*samples)[*count];
        if (sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &sample->values[0],
            &sample->values[1],
            &sample->values[2],
            &sample->values[3],
            &sample->values[4],
            &sample->values[5],
            &sample->values[6],
            &sample->values[7]) == 8)
        {
            (*count)++;
        }




    }
    // Close the file
        fclose(fptr);
}

void output(FILE *out,
    v_results aRes,
    v_results bRes,
    v_results cRes,
    double freq_min,
    double freq_max,
    double freq_mean,
    double thd_min,
    double thd_max,
    double pf_min,
    double pf_max,
    int clipped
    )
{


    const char *cA = (aRes.rms >= 207.0 && aRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";
    const char *cB = (bRes.rms >= 207.0 && bRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";
    const char *cC = (cRes.rms >= 207.0 && cRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";

    fprintf(out,"--- :) Power Quality Analysis :) ---\n");
    fprintf(out,"Phase A RMS: %.5f V (within 207-253 V tolerance band - %s)\n", aRes.rms, cA);
    fprintf(out,"Phase A peak-to-peak: %.3f V\n", aRes.peak_peak);
    fprintf(out,"Phase A DC offset: %.3f V\n", aRes.offset);
    fprintf(out,"Phase B RMS: %.5f V (%s)\n", bRes.rms, cB);
    fprintf(out,"Phase B peak-to-peak: %.3f V\n", bRes.peak_peak);
    fprintf(out,"Phase B DC offset: %.3f V\n", bRes.offset);
    fprintf(out,"Phase C RMS: %.5f V (%s)\n", cRes.rms, cC);
    fprintf(out,"Phase C peak-to-peak: %.3f V\n", cRes.peak_peak);
    fprintf(out,"Phase C DC offset: %.3f V\n", cRes.offset);
    fprintf(out,"Clipped samples (|V| >= 324.9 V, any phase): %d samples total\n", clipped);
    fprintf(out,"Frequency range: %.5f Hz to %.5f Hz. Mean frequency drifted from nominal value (50Hz) by %.3f \n", freq_min, freq_max,(freq_mean-50.0));
    fprintf(out,"Power factor range: %.3f to %.3f\n", pf_min, pf_max);
    fprintf(out,"THD range: %.2f%% to %.2f%%\n", thd_min, thd_max);

}

int report()
{
    char inputFile[512];

    // Get input CSV path
    printf("Enter input CSV filename (full path allowed): ");
    fgets(inputFile, sizeof(inputFile), stdin);
    inputFile[strcspn(inputFile, "\n")] = 0; // remove newline

    FILE *log = fopen("report.txt", "w");
    if (!log) {
        perror("Could not open report.txt");
        return 1;
    }

    int flag = calc(inputFile, log);
    if (flag == 0) {
        printf("\nProcess finished successfully. Report saved to report.txt\n");
    } else {
        printf("\nProcess failed.\n");
    }

    return flag;
}
