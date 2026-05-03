//
// Created by loran on 10/04/2026.
//

#include "io.h"
#include "waveform.h"


void fetchSamples(waveformSample **samples, size_t *count)
{
    FILE *fptr = fopen("power_quality_log.csv", "r");
    if (fptr == NULL) {
        perror("Failed to open file");
        return;
    }

    *samples = NULL;
    size_t capacity = 32;
    *count = 0; // size_t type allows safe large mallocs without risk of overflow
    *samples = malloc(sizeof(waveformSample) * capacity);

    if (*samples == NULL) {
        perror("Initial allocation failed");
        fclose(fptr);
        return;
    }

    char line[256];

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
                free(samples);
                fclose(fptr);
                return;
            }
            *samples = buffer;
        }
        //parse values to struct

        waveformSample *sample = &(*samples)[*count];
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &sample->values[0],
            &sample->values[1],
            &sample->values[2],
            &sample->values[3],
            &sample->values[4],
            &sample->values[5],
            &sample->values[6],
            &sample->values[7]);
        samples[*count] = sample;
        (*count)++;
    }



    // Close the file
    fclose(fptr);
    }

void output(FILE *out, v_results aRes, v_results bRes, v_results cRes, int clipped)//+freq,pf,thd
{


    const char *cA = (aRes.rms >= 207.0 && aRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";
    const char *cB = (bRes.rms >= 207.0 && bRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";
    const char *cC = (cRes.rms >= 207.0 && cRes.rms <= 253.0) ? "COMPLIANT" : "NON-COMPLIANT";

    fprintf(out,"--- :) Power Quality Analysis :) ---\n");
    fprintf(out,"Phase A RMS: %.1f V (within 207-253 V tolerance band - %s)\n", aRes.rms, cA);
    fprintf(out,"Phase A peak-to-peak: %.1f V\n", aRes.peak_peak);
    fprintf(out,"Phase A DC offset: %.2f V\n", aRes.offset);
    fprintf(out,"Phase B RMS: %.1f V (%s)\n", bRes.rms, cB);
    fprintf(out,"Phase B peak-to-peak: %.1f V\n", bRes.peak_peak);
    fprintf(out,"Phase B DC offset: %.2f V\n", bRes.offset);
    fprintf(out,"Phase C RMS: %.1f V (%s)\n", cRes.rms, cC);
    fprintf(out,"Phase C peak-to-peak: %.1f V\n", cRes.peak_peak);
    fprintf(out,"Phase C DC offset: %.2f V\n", cRes.offset);
    fprintf(out,"Clipped samples (|V| >= 324.9 V, any phase): %d samples total\n", clipped);
    fprintf(out,"Frequency range: %.3f Hz to %.3f Hz\n", freq_min, freq_max);
    fprintf(out,"Power factor range: %.3f to %.3f\n", pf_min, pf_max);
    fprintf(out,"THD range: %.2f%% to %.2f%%\n", thd_min, thd_max);

}

int report()
{
    char file_to_read[255];
    printf("Enter filename to read from : ");
    scanf("%s", file_to_read);
    FILE *log = fopen("report.txt", "w");
    if (log == NULL) {
        perror("could not open report.txt");
        return 1;
    }

    int flag = calc(file_to_read,log);
    printf("\n process finished");
    getchar();
    fclose(log);
    return flag;
}
