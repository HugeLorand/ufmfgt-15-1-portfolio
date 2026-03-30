#include <stdlib.h>
int main(){
    int x1 = 10, x2 = 20, x3;
    int *ptr1, *ptr2, *ptr3;
    printf("Addresses of x1, x2, x3: %p %p %p\n\n", &x1, &x2, &x3);
    printf("Press Enter to continue......");
    getchar();
/* BAD
printf(" Object pointed to by uninitialised ptr1 = %d\n", *ptr1);
printf("Press Enter to continue......");
getchar();
*/
    ptr1 = &x1;
    printf("ptr1 now holds the address:%p\n\n", ptr1);
    printf("Value pointed to by ptr1= %d\n\n", *ptr1);
    printf("Press Enter to continue......");
    getchar();
    ptr2 = ptr1;
    printf("Value pointed to by ptr2 = %d\n\n", *ptr2);
/* BAD
*ptr3 = 99;
*/
    ptr2 = &x2;
    ptr3 = &x3;
    *ptr3 = *ptr1 + *ptr2;
    printf("New value of x3 = %d\n\n", x3);
    return 0;

}