#include<stdio.h>

int getInput();                        //Retrieves the year.
void checkLeapStatus(int, int*, int*); //Checks to see if it is a leap year.
int calcDay(int, int);                 //Calculates day on 12/31 of last year.
int calcTaxDay(int, int);              //Calculates the day in April.
void displayResults(int, int);         //Displays the calculated results.

int main()
{
    int year = 0;       //The year the user inputs.
    int num_days = 0;   //The number of days in the current year.
    int num_days_l = 0; //The number of days in the last year.
    int day = 0;        //The day it was on dec 31 of previous year.
    int tax_day = 0;    //The day in April taxes are due.

    //Gathers input from the user.
    year = getInput(year);
    //Checks if it is a leap year.
    checkLeapStatus(year, &num_days, &num_days_l);
    //Calculates "day" value.
    day = calcDay(year, num_days_l);
    //Calculates the day value of the tax day (April 15th).
    tax_day = calcTaxDay(day, num_days);
    //Displays the results.
    displayResults(tax_day, year);

    return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getdata
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. None
*
*     Function Description: Prompts the user to input the year they wish
*     to know the tax day of.
*
***************************************************************************/
int getInput()
{
    int year = 0; //The given year.
    
    //Prompts user to enter a year.
    printf("\nEnter the year: ");
    scanf("%d", &year);

    return(year);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkLeapStatus
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year:        The year of the tax day.
*       2. int* num_days:   The number of days in current year.
*       3. int* num_days_l: The number of days in last year.
*
*     Function Description: Calculates the amount of days in the user's
*     given year and the year before that.
*
***************************************************************************/
void checkLeapStatus(int year, int* num_days, int* num_days_l)
{
    //If the year divided by 4 has no remainer and the year divided by 100 has
    //a remainer OR the year divided by 100 has a remainder, amount of days in
    //the year is 366.  Otherwise, it is 365.
    if ((!(year % 4) && (year % 100)) || !(year % 100))
    {
        *num_days = 366;
    }
    else
    {
        *num_days = 365;
    }

    //Year decrimented by 1 to calculate days of prior year.  
    year -= 1;

    //Refer to top comment.
    if ((!(year % 4) && (year % 100)) || !(year % 100))
    {
        *num_days_l = 366;
    }
    else
    {
        *num_days_l = 365;
    }

    return;
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcDay
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year:       The year of the tax day.
*       2. int num_days_l: The number of days in the previous year.
*
*     Function Description: Determines what day it was on december 31st of
*     the previous year.
*
***************************************************************************/
int calcDay(int year, int num_days_l)
{
     int day = 0; //The day of December 31st of the previous year.
    
     //Using the given number of days in the year, will calculate the day vaue
     //0 to 6 based upon which day it was Dec 31st of the last year.
     day = ((year - 1) * num_days_l + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
                                                            
     return(day);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcTaxDay
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day:      Day on dec 31 of prior year.
*       2. int num_days: The number of days in the current year.
*
*     Function Description: Determines what day it is on April 15th.
*
***************************************************************************/
int calcTaxDay(int day, int num_days)
{
    int tax_day = 0; //The day on April 15th.

    //If the number of days of current year is 366 (is leap year).
    if (num_days == 366)
    {
        //Value of day of April 15th increased by one due to leap year shift.
        tax_day = day + 1;

        //If the previous increment caused the value of "tax_day" to become
        //greater than the maximum (6), reset to beginning (0).
        if (tax_day > 6)
        {
            tax_day = 0;
        }
    }
    //If year is a common year.
    else
    {
        tax_day = day;
    }

    return(tax_day);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayResults
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int tax_day: The day on April 15th of the current year.
*       2. int year:    The year of the tax day.
*
*     Function Description: Prints out the day one which taxes are collected.
*
***************************************************************************/
void displayResults(int tax_day, int year)
{
    //Prints the first part of the text, restating the user's given year.
    printf("April 15th, %d is on a ", year);

    //Day on April 15th (0-6) used as switch.
    switch(tax_day)
    {
        //If it is Sunday (0).
        case(0):
            printf("Sunday and tax day will take place on Monday April 16th.");
            break;
        //If it is Monday (1).
        case(1):
            printf("Moday.");
            break;
        //If it is Tuesday (2).
        case(2):
            printf("Tuesday.");
            break;
        //If it is Wednesday (3).
        case(3):
            printf("Wednesday.");
            break;
        //If it is Thursday (4).
        case(4):
            printf("Thursday.");
            break;
        //If it is Friday (5).
        case(5):
            printf("Friday and tax day will take place on Monday April 18th.");
            break;
        //If it is Saturday (6).
        case(6):
            printf("Saturday and tax day will take place on Monday April 17th.");
    }

    //Additional newlines for formatting.
    printf("\n\n");

    return;
}