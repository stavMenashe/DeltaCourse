/*------------------------------------------------------
* Filename: CalcAge.c
* Description: Calculates the age of the user in days, months and years.
* Author: Stav Menashe.
-------------------------------------------------------*/
#include <stdio.h>

#define DAYS_IN_MONTH (30)
#define DAYS_IN_YEAR (365)

int main() {
    int curr_day, curr_month, curr_year;
    int birth_day, birth_month, birth_year;
    double days_gap = 0, months_gap = 0, years_gap = 0;
    double age_in_days = 0, age_in_months = 0, age_in_years = 0;

    printf("Please enter the date (format dd/mm/yyyy): ");
    scanf("%d/%d/%d", &curr_day, &curr_month, &curr_year);
    printf("Please enter your birth date (format dd/mm/yyyy): ");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);

    days_gap = curr_day - birth_day;
    months_gap = curr_month - birth_month;
    years_gap = curr_year - birth_year;

    age_in_days = days_gap + (months_gap * DAYS_IN_MONTH) + (years_gap * DAYS_IN_YEAR);
    age_in_months = age_in_days / DAYS_IN_MONTH;
    age_in_years = age_in_days / DAYS_IN_YEAR;

    printf("Your age in days is: %f\n", age_in_days);
    printf("Your age in months is: %f\n", age_in_months);
    printf("Your age in years is: %f\n", age_in_years);

    return 0;
}