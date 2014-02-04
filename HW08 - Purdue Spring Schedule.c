#include <stdio.h>
#define JAN_DAYS 31      //Total of 31 days in Janurary.
#define MAX_DAYS_SEM 117 //Total of 117 days in the semester.
#define LEAP_ORDER_1 4   //First divison to calculate leap year.
#define LEAP_ORDER_2 100 //Second division to calculate leap year.
#define LEAP_ORDER_3 400 //Third division to calculate leap year.
#define LEAP_ORDER_F 7   //Final modulus to find day value.

int getInput();                           //Retrieves the year.
void checkLeapStatus(int, int*, int*);    //Checks for days of year and last
                                          //year.
int calcDecDay(int, int);                 //Calculates day of Dec 31st of lsat
                                          //year.
int calcSpringSem(int);                   //Calculates the day spring semester
                                          //begins.
int calcMaxDays(int, int, int, int*);     //Calculates max days in month.
void printCalendarFrame(int, int);        //Prints the frame of the calendar.
int printCalendarNum(int, int, int, int); //Prints the dates of the calendar.
void checkTabEnd(int, int, int);          //Check for weekends to tab.
int calcJanMons(int, int);                //Finds Mondays in missing days.
int checkTabMLKD(int, int, int*, int*);   //Finds and tabs MLK day.
int checkTabSB(int, int, int*, int*);     //Finds and tabs spring break.

int main()
{
    int year = 0;          //The given year.
    int num_days = 0;      //Number of days this year.
    int num_days_l = 0;    //Number of days last year.
    int day = 0;           //The day of Dec 31st of last year.
    int spring_sem = 0;    //The date spring semester begins.
    int max_days = 0;      //The maximum number of says in the given month.
    int month = 1;         //The current month value (1 = Jan, 2 = Feb, etc.).
    int max_days_curr = 0; //The current total of days in the semester.

    //Recives the year.
    year = getInput();
    //Checks for days of year and last year.
    checkLeapStatus(year, &num_days, &num_days_l);
    //Calculates day of Dec 31st of last year.
    day = calcDecDay(year, num_days_l);
    //Calculates the date at which the spring semester begins.
    spring_sem = calcSpringSem(day);
  
    //Loops through al 5 months of the spring semester in order to print all
    //the required frame and date sets.
    while (month < 6)
    {
        //Calculates the amount of days in any given month.
        max_days = calcMaxDays(month, num_days, spring_sem, &max_days_curr);
        //Prints the frame of the calendar.
        printCalendarFrame(month, day);
        //Prints the dates of the calendar.
        day = printCalendarNum(max_days, day, spring_sem, month);
        //Increments the month value by 1.
        month++;
    }

    //The last of the newlines.
    printf("\n\n");

    return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getInput
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. None
*
*     Function Description: Prompts the user to input the year.
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
*     Function Information:
*
*     Name of Function: checkLeapStatus
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year:        The year being used.
*       2. int* num_days:   The number of days in current year.
*       3. int* num_days_l: The number of days in last year.
*
*     Function Description: Calculates the amount of days in the user's
*     given year and the year before that.
*
***************************************************************************/
void checkLeapStatus(int year, int* num_days, int* num_days_l)
{
    int last_year = year - 1; //The Previous year.

    //If the year divided by 4 has no remainder and the year divided by 100 has
    //a remainder OR the year divided by 100 has a remainder, amount of days in
    //the year is 366.  Otherwise, it is 365.
    if ((!(year % LEAP_ORDER_1) && (year % LEAP_ORDER_2)) || !(year % LEAP_ORDER_2))
    {
        *num_days = 366;
    }
    else
    {
        *num_days = 365;
    }

    //Refer to top comment.
    if ((!(last_year % LEAP_ORDER_1) && (last_year % LEAP_ORDER_2)) || !(last_year % LEAP_ORDER_2))
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
*     Name of Function: calcDecDay
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year:       The year being used.
*       2. int num_days_l: The number of days in the previous year.
*
*     Function Description: Determines what day it was on december 31st of
*     the previous year.
*
***************************************************************************/
int calcDecDay(int year, int num_days_l)
{
    int day = 0;                   //The day of December 31st of the previous
                                   //year.
    int num_days = -1;             //The days of the current year.
    int last_year = year - 1;      //The previous year.
    int last_last_year = year - 2; //The year before the previous year.

    //If the previous year was not a leap year.
    if (num_days_l != 366)
    {
        //Using the given number of days in the year, will calculate the day
        //value 0 to 6 (Sunday to Saturday) based upon which day it was on
        //Dec 31st of the last year.
        day = (last_year * num_days_l + (last_year / LEAP_ORDER_1) - (last_year / LEAP_ORDER_2) + (last_year / LEAP_ORDER_3)) % LEAP_ORDER_F;
    }
    //If the previous year was a leap year.
    else
    {
        num_days += num_days_l;
        //Same as above; does this with the year befor the previous in order
        //to correct algorithm day calculation mistake giving bad day values
        //after a leap year by continueing the Dec 31st day value trend, adding
        //"2" to the last last year day value.
        day = (last_last_year * num_days + (last_last_year / LEAP_ORDER_1) - (last_last_year / LEAP_ORDER_2) + (last_last_year / LEAP_ORDER_3)) % LEAP_ORDER_F;
        day += 2;
        
        //If the addition of "2" has caused the day value to surpass its max
        //value, "6", subtract 7 (to allow for 0) to gain propper value.
        if (day > 6)
        {
            day -= 7;
        }
    }
  
    return(day);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcSpringSem
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day: The day of Dec 31st previous year.
*
*     Function Description: Finds the date at which the spring semester will
*     begin.
*
***************************************************************************/
int calcSpringSem(int day)
{
    int spring_sem = 0; //The date of the spring semester.
    
    switch (day)
    {
    //If Dec 31st is Sunday.
    case(0): //Spring semester begins Jan 8th.
             spring_sem = 8;
             break;
    //If Dec 31st is Monday.
    case(1): //Spring semester begins Jan 7th.
             spring_sem = 7;
             break;
    //If Dec 31st is Tuesday.
    case(2): //Spring semester begins Jan 6th.
             spring_sem = 6;
             break;
    //If Dec 31st is Wednesday.
    case(3): //Spring semester begins Jan 5th.
             spring_sem = 5;
             break;
    //If Dec 31st is Thursday.
    case(4): //Spring semester begins Jan 11th.
             spring_sem = 11;
             break;
    //If Dec 31st is Friday.
    case(5): //Spring semester begins Jan 10th.
             spring_sem = 10;
             break;
    //If Dec 31st is Saturday.
    case(6): //Spring semester begins Jan 9th.
             spring_sem = 9;
    }

    return(spring_sem);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcMaxDays
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month:          The current month value.
*       2. int num_days:       The number of days in the current year.
*       3. int spring_sem:     The date at which spring semester begins.
*       4. int* max_days_curr: The current total of days in the semester.
*
*     Function Description: Finds the maximum amount of days in the current
*     month.
*
***************************************************************************/
int calcMaxDays(int month, int num_days, int spring_sem, int* max_days_curr)
{
    int max_days = 0;      //Maximum days in month send for calculation.

    //If month is Janurary.
    if (month == 1)
    {
        //Max is total january days minus the day spring semester begins.
        max_days = JAN_DAYS - spring_sem;
        //Adds Janurary days to total.
        *max_days_curr += max_days;
    }
    //If month is February.
    else if (month == 2)
    {
        //Leap year check.
        if (num_days == 365)
        {
            //Non-leap year.
            max_days = 28;
        }
        else
        {
            //Leap year.
            max_days = 29;
        }
        //Adds February days to total.
        *max_days_curr += max_days;
    }
    //If month is March.
    else if (month == 3)
    {
        max_days = 31;
        //Adds March days to total.
        *max_days_curr += max_days;
    }
    //If month is April.
    else if (month == 4)
    {
        max_days = 30;
        //Adds April days to total.
        *max_days_curr += max_days;
    }
    //If month is May.
    else if (month == 5)
    {
        //Finds May days by subtracting the sum of days already printed from
        //the total amount of days that can be in the semester.
        max_days = MAX_DAYS_SEM - *max_days_curr;
    }

    return(max_days);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printCalendarNum
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int max_days: The maximum amount of days in the current month.
*       2. int days:     The day value.
*
*     Function Description: Prints the dates of the current month.
*
***************************************************************************/
int printCalendarNum(int max_days, int day, int spring_sem, int month)
{
    int curr_date = 0; //The current date to be printed.
    int mlkd = 0;      //The Monday counter for Martin Luther King day.
    int sb = 1;        //The Monday counter for Spring Break.

    //Loops printing each date in the calendar under the maximum days of the
    //selected month until it has printed all days as given by max_days.
    for (curr_date = 1; curr_date <= max_days; curr_date++)
    {
        //If it is the bgeinning of January.
        if ((month == 1) && (curr_date == 1))
        {
            //Find Mondays in unlisted January days.
            mlkd = calcJanMons(day, spring_sem);
          
            //Proceed with standar setting of January start dates; January
            //always begins on a Monday at the calculated spring semester
            //date.
            day = 1;
            curr_date = spring_sem;
            max_days += spring_sem;        
        }
 
        //Check for MLK day.
        mlkd = checkTabMLKD(month, mlkd, &day, &curr_date);

        //Check for spring break.
        sb = checkTabSB(month, sb, &day, &curr_date);

        //Checks if it is a Saturday or Sunday; prints regularly if false.
        checkTabEnd(day, month, curr_date);
      
        //Wrap around check; if day value reaches 6 (sunday) and the
        //printing has not reached the max_days value, day value is
        //reset to 0 (saturday) and printing is reset to the next line.
        if ((day >= 6) && (curr_date != max_days))
        {
            printf("\n");
            day = 0;
        }
        else if (day == 6)
        {
            day = 0;
        }
        //If above is not met, day is incremented.
        else
        {
            day++;
        }
    }

    return(day);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkTabSB
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month:      The month that the counter is currently at.
*       2. int sb:         The Monday counter for spring break.
*       3. int* day:       The day that the counter is currently at.
*       4. int* curr_date: The date that th counter is currently at.
*
*     Function Description: Finds and tabs spring break.
*
***************************************************************************/
int checkTabSB(int month, int sb, int* day, int* curr_date)
{
    //On every Monday of March, check to see if it is spring break.
    //If yes, print tab and increment day and date to make up for the gap as
    //well as increment the spring break counter to prevent future printing.
    if ((month == 3) && (*day == 1) && (*curr_date >= 1) && (sb == 2))
    {
        printf("               ");
        *curr_date = *curr_date + 5;
        *day = *day + 5;
        sb++;
    }
    //If the Monday was not spring break, add the Monday to the counter.
    else if ((month == 3) && (*day == 1) && (*curr_date >= 1) && (sb < 3))
    {
        sb++;
    }

    return(sb);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkTabMLKD
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month:      The month that the counter is currently at.
*       2. int mlkd:       The Monday counter for MLK day.
*       3. int* day:       The day that the counter is currently at.
*       4. int* curr_date: The date that th counter is currently at.
*
*     Function Description: Finds and tabs MLK day.
*
***************************************************************************/
int checkTabMLKD(int month, int mlkd, int* day, int* curr_date)
{
    //On every Monday of January...
    if ((month == 1) && (*day == 1))
    {
        //...check to see if it is Martin Luther King day (3rd Monday).
        //If yes, print tab, reset counter to 1, and add 1 to the day
        //and date counters to make up for the gap.
        if (mlkd == 3)
        {
            printf("   ");
            mlkd = 1;
            *curr_date = *curr_date + 1;
            *day = *day + 1;
        }
        //If not, count the Monday and add one to the counter.
        else
        {
            mlkd++;
        }
    }

    return(mlkd);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcJanMons
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day:        The day that the counter is currently at.
*       2. int spring_sem: The date that spring semester begins.
*
*     Function Description: Finds the Mondays in the unlisted January days.
*
***************************************************************************/
int calcJanMons(int day, int spring_sem)
{
    int mlkd = 0; //Martin Luther King day counter.
    int jan = 0;  //Missing January days counter.
    
    //Loops in order to calculate the missing dates and their various
    //Modays that are required to calculate when Martin Luther King
    //day will be.
    for (jan = 1; jan <= spring_sem; jan++)
    {
          //Increment day.
          day++;
          //If is is Sunday, restart week.
          if (day == 6)
          {
              day = 0;
          }
          //If it is Monday, add one to the Martin Luther King day Monday
          //counter.
          else if (day == 1)
          {
              mlkd++;
          }
    }

    return(mlkd);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkTabEnd
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day:       The day that the counter is currently at.
*       2. int month:     The month that the counter is currently at.
*       3. int curr_date: The date that the counter is currently at.
*
*     Function Description: Checks to see if it can put tabs into weekends;
*     prints regularly if it cannot.
*
***************************************************************************/
void checkTabEnd(int day, int month, int curr_date)
{
    //If the day is Saturday or Sunday not in May, place tab.
    if ((day == 0) || ((day == 6) && (month != 5)))
    {
        printf("   ");
    }
    //If regular day, print date.
    else
    {
        printf("%3.d", curr_date);
    }

    return;
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printCalendarFrame
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month: The current month to print.
*       2. int day:   The day value of Dec 31 of last year.
*
*     Function Description: Will print the general frame of the calendar.
*
***************************************************************************/
void printCalendarFrame(int month, int day)
{
    int tab = 0;
    int counter = 0;
    
    printf("\n");

    switch(month)
    {
    case(1): //If month is val 1, Januray.
             printf("Januray\n");
             day = 1;
             break;
    case(2): //If month is val 2, February.
             printf("\nFebruary\n");
             break;
    case(3): //If month is val 3, March.
             printf("\nMarch\n");
             break;
    case(4): //If month is val 4, April.
             printf("\nApril\n");
             break;
    case(5): //If month is val 5, May.
             printf("\nMay\n");
    }

    //Print calendar day header.
    printf("  S  M Tu  W Th  F  S\n");

    //tab, number of tabs, is equal to one more than the date value (0 to 6);
    //for every additional day between sunday and saturday, additional tabs are
    //added so that the calendar is positioned correctly.
    tab += day;

    while (counter < tab)
    {
        printf("   ");
        counter++;
    }

    return;
}