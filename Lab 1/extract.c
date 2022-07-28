// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include <stdbool.h>
#include<string.h>

typedef unsigned char BYTE;


int indi(int num){
    int digit;
    while(num != 0){
        digit = num % 10;
        num = num / 10;
    }
    return digit;
}


int main(){
    unsigned int value = 257; 

    int a, b, c, d; 

    a = (value & 0xff); 
    b = ((value >> 8) & 0xff); 
    c = ((value >> 16) & 0xff);
    d = ((value >> 24) & 0xff); 

    printf("a= %d\n", a);
    printf("b= %d\n", b);
    printf("c= %d\n", c);
    printf("d= %d\n", d);

    return 0;
}

