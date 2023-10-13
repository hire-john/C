
/*
 * McDonnell Buffer Overflow Conditions
 */

#include <stdio.h>

int main() {
    /* declare array of 10 ints */

    int n[10];
    int i, j;

    /* initialize elements of array */
    for (i=0; i<=9; i++){
        n[i] = i + 100;
    }

    /* initialize elements of array */
    for(j=0; j < 10; j++){
        printf("Element[%d] = %d\n", j, n[j]);
    }

    printf("Element[%d] = %d\n", j, n[10]);

    return 0;
}
