#include<stdio.h>
#define FEETTOMETER 0.3048
int main()
{
    float weight, height, bmi;
    printf("Enter your weight: ");
    scanf("%f", &weight);

    printf("Enter your height(in feet):");
    scanf("%f", &height);

    height = height * FEETTOMETER;

    bmi = (weight)/(height * height);
    printf("Your BMI is: %f\n", bmi);
    return 0;
}
