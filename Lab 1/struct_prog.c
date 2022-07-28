// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include <stdbool.h>
#include<string.h>

struct A{
    int roll;
    char name[50];
    float cgpa;
};

void disp(struct A *h2){
    printf("%d %s %f", h2->roll, h2->name, h2->cgpa);
}

int main(){
    struct A h1;
    h1.roll = 65;
    strcpy(h1.name, "anita");
    h1.cgpa = 10.00;
    disp(&h1);
    return 0;
}