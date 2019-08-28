#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(){
    int int_var = INT_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;

    printf("%lu %lu %lu", sizeof(int_var), sizeof(float_var), sizeof(double_var));
    printf("\n%d\n%lf\n%lf\n", int_var, float_var, double_var);

}