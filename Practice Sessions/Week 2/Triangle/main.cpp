#include <stdio.h>
#include <math.h>

int main(void) {
    int height = 0;
    int length = 0;
    printf("Please enter values for height and length of right-angled triangle \n");
    scanf("%d", &height);
    scanf("%d", &length);
    int hypotenuse = sqrt(height*height+length*length);
    int area = height*length/2;
    int perim = height+length+hypotenuse;
    printf("Your triangle has area %d and perimeter %d", area, perim);

    return 0;
}
