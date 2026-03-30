#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec){
*hr = total_sec/3600;
*min = (total_sec%3600)/60;
*sec = total_sec%60;
}

int main() {
    printf("Please input how many seconds have passed since midnight\n");
    int hr,min,sec;
    long total_sec = 0;
    scanf("%d",&total_sec);
    split_time(total_sec,&hr,&min,&sec);
    printf("Time:   %d:%d:%d\n",hr,min,sec);
    return 0;

}