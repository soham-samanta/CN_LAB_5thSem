// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include <stdbool.h>
#include<string.h>

int main(){
    int x,y,*ptr_x,*ptr_y,temp;

    printf("Enter the value of x and y\n");
    scanf("%d%d", &x, &y);

    printf("Before Swapping\nx = %d\ny = %d\n", x, y);

    ptr_x = &x;
    ptr_y = &y;

    temp = *ptr_y;
    *ptr_y = *ptr_x;
    *ptr_x = temp;

    printf("After Swapping\nx = %d\ny = %d\n", x, y);

    return 0;
}