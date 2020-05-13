#include<stdio.h>
#include<stdlib.h>


struct _retire_info{
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct _retire_info  retire_info;

void retirement (int startAge, double initial,  retire_info working,  retire_info retired)
{
    double current_blance = initial;
    int age = startAge;
    for (int i = 0;i < working.months; i++)
    {
        printf("Age %3d month %2d you have $%.2lf\n" , age/12, age%12, current_blance);
        current_blance = current_blance + current_blance*working.rate_of_return;
        current_blance = current_blance + working.contribution;
        age = age +1;
    }
    for (int j = 0;j < retired.months;j++ )
    {
        printf("Age %3d month %2d you have $%.2lf\n" , age/12, age%12, current_blance);
        current_blance = current_blance + current_blance*retired.rate_of_return;
        current_blance = current_blance + retired.contribution;
        age = age +1;

    }
}

int main(void){

    retire_info working_period;
    retire_info retired_period;

    working_period.months = 489;
    working_period.contribution = 1000;
    working_period.rate_of_return = 0.045/(double)12;

    retired_period.contribution = -4000;
    retired_period.months = 384;
    retired_period.rate_of_return = 0.01/(double)12;

    int start_age = 327;
    double start_blance = 21345;

    retirement(start_age, start_blance, working_period,retired_period);

    return EXIT_SUCCESS;
}

