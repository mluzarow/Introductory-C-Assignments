#include<stdio.h>

int getInput();                        //Retrieves the year.
void checkLeapStatus(int, int*, int*); //Checks to see if it is a leap year.
int calcDay(int, int);                 //Calculates day on 12/31 of last year.
int calcSpringSem(int);                //Calculates the day of Spring Semester.
int calcLeapOffset(int, int);          //Calculates the day on/after 02/28.
int calcSpringBreak(int, int);         //Calculates the days of Spring Break.
int calcFinal(int, int);               //Calculates the days of finals.
void displaySpringSem(int, int);       //Displays the day of spring semester.
void displaySpringBreak(int, int);     //Displays the days of spring break.
void displayFinal(int, int);           //Displays the days of the finals.

int main()
{
    int year = 0;          //The year the user inputs.
    int num_days = 0;      //The number of days in the current year.
    int num_days_l = 0;    //The number of days in the last year.
    int day = 0;           //The day it was on dec 31 of previous year.
    int leap_offset = 0;   //The day value with leap year offset.
    int spring_sem = 0;    //The day the spring semester begins.
    int spring_break = 0;  //The day spring break begins and lasts.
    int final = 0;         //The day finals begin and last.

    //Gathers the year from the user.
    year = getInput();
    //Checks if it is a leap year and returns the propper amount of days.
    checkLeapStatus(year, &num_days, &num_days_l);
    //Calculates the "day" value
    day = calcDay(year, num_days_l);
    //Calculates the "day" value after Feb 28th (leap year checking).
    leap_offset = calcLeapOffset(day, num_days);
    //Calculates the date of the spring semester.
    spring_sem = calcSpringSem(day);
    //Calculates the date of spring break.
    spring_break = calcSpringBreak(spring_sem, num_days);
    //Calculates the date of the finals.
    final = calcFinal(spring_sem, num_days);
    //Displays the date of the spring semester.
    displaySpringSem(year, spring_sem);
    //Displays the dates of spring break.
    displaySpringBreak(year, spring_break);
    //Displays the dates of the finals.
    displayFinal(year, final);

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
*     Function Description: Prompts the user to input the year they wish
*     to know the dates of.
*
***************************************************************************/
int getInput()
{
    int year = 0; //The given year.

    //Prompts user to enter a year.
    printf("\nEnter the year: ");
    scanf("%d", &year);

    printf("\n");

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
*       1. int year:        The year being used.
*       2. int* num_days:   The number of days in the current year.
*       3. int* num_days_l: The number of days in the last year.
*
*     Function Description: Calculates the amount of days in the user's
*     given year and the year before that.
*
***************************************************************************/
void checkLeapStatus(int year, int* num_days, int* num_days_l)
{
    int last_year = year - 1; //The previous year.

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

    //Refer to top comment.
    if ((!(last_year % 4) && (last_year % 100)) || !(last_year % 100))
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
     int day = 0;              //The day of December 31st of the previous year.
     int last_year = year - 1; //The previous year.

     //Using the given number of days in the year, will calculate the day vaue
     //0 to 6 based upon which day it was Dec 31st of the last year.
     day = (last_year * num_days_l + (last_year / 4) - (last_year / 100) + (last_year / 400)) % 7;
  
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
*       1. int day: Day on dec 31 of prior year.
*
*     Function Description: Calculates the date of the start of the spring
*     semester.
*
***************************************************************************/
int calcSpringSem(int day)
{
    int spring_sem = 0; //The date of the spring semester.

    switch(day)
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
*     Name of Function: calcLeapOffset
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day:      Day on dec 31 of prior year.
*       2. int num_days: The number of days in the current year.
*
*     Function Description: Determines what day it is after 02/28.
*
***************************************************************************/
int calcLeapOffset(int day, int num_days)
{
    int leap_offset = 0; //The day on/after 02/28.

    //If the number of days of current year is 366 (is leap year).
    if (num_days == 366)
    {
        //Value of day of April 15th increased by one due to leap year shift.
        leap_offset = day + 1;

        //If the previous increment caused the value of "tax_day" to become
        //greater than the maximum (6), reset to beginning (0).
        if (leap_offset > 6)
        {
            leap_offset = 0;
        }
    }
    //If year is a common year.
    else
    {
        leap_offset = day;
    }

    return(leap_offset);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcSpringBreak
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int spring_sem:  The date of spring semester.
*       2.int num_days:    The days in the year.
*
*     Function Description: Finds the dates of spring break.
*
***************************************************************************/
int calcSpringBreak(int spring_sem, int num_days)
{
    int sbday = 0; //The date spring break begins.
    
    if (num_days == 366)
    {
       sbday = spring_sem + 67;

       switch(sbday)
       {
         case 67: sbday = 3;
         break;
         case 68: sbday = 4;
         break;
         case 69: sbday = 5;
         break;
         case 70: sbday = 6;
         break;
         case 71: sbday = 7;
         break;
         case 72: sbday = 8;
         break;
         case 73: sbday = 9;
         break;
         case 74: sbday = 10;
         break;
         case 75: sbday = 11;
         break;
         case 76: sbday = 12;
       }
    }
    else
    {
       sbday = spring_sem + 66;
      
       switch(sbday)
       {
         case 67: sbday = 5;
         break;
         case 68: sbday = 6;
         break;
         case 69: sbday = 7;
         break;
         case 70: sbday = 8;
         break;
         case 71: sbday = 9;
         break;
         case 72: sbday = 10;
         break;
         case 73: sbday = 11;
         break;
         case 74: sbday = 12;
         break;
         case 75: sbday = 13;
         break;
         case 76: sbday = 14;
         break;
         case 77: sbday = 15;
         break;
         case 78: sbday = 16;
       }
    }
    
    return(sbday);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcFinal
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int spring_sem:  The date of spring semester.
*       2.int num_days:    The days in the year.
*
*     Function Description: Finds the dates of finals
*
***************************************************************************/
int calcFinal(int spring_sem, int num_days)
{
     int final = 0; //The day finals begin.

     if (num_days == 366)
     {
       final = spring_sem + 67;

       switch(final)
       {
         case 67: final = 21;
         break;
         case 68: final = 22;
         break;
         case 69: final = 23;
         break;
         case 70: final = 24;
         break;
         case 71: final = 25;
         break;
         case 72: final = 26;
         break;
         case 73: final = 27;
         break;
         case 74: final = 28;
         break;
         case 75: final = 29;
         break;
         case 76: final = 30;
      }
    }
    else
    {
      final = spring_sem + 66;

      switch(final)
      {
        case 67: final = 23;
        break;
        case 68: final = 24;
        break;
        case 69: final = 25;
        break;
        case 70: final = 26;
        break;
        case 71: final = 27;
        break;
        case 72: final = 28;
        break;
        case 73: final = 29;
        break;
        case 74: final = 30;
        break;
        case 75: final = 1;
        break;
        case 76: final = 2;
        break;
        case 77: final = 3;
        break;
        case 78: final = 4;
     }
   }

    return(final);
}
/***************************************************************************
*
*     Function Information
*
*     Name of Function: displaySpringSem
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year:       The given year.
*       2. int spring_sem: The day that the spring semester begins.
*
*     Function Description: Displays when the spring semester begins.
*
***************************************************************************/
void displaySpringSem(int year, int spring_sem)
{
    //Prints the first part of the text, restating the user's given year.
    printf("The start of the Spring %d semester will be: Monday January %d", year, spring_sem);

    //Checks date to see which suffix to add.
    switch(spring_sem)
    {
    case(1): //If date is 1st.
             printf("st");
             break;
    case(2): //If date is 2nd.
             printf("nd");
             break;
    case(3): //If date is 3rd.
             printf("rd");
             break;
    default: //If date is anything else.
             printf("th");
    }

    //Additional newlines for formatting.
    printf("\n");

    return;
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displaySpringBreak
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year:         The given year.
*       2.int spring_break: The date at which spring break begins.
*
*     Function Description: Displays the dates of spring break.
*
***************************************************************************/
void displaySpringBreak(int year, int spring_break)
{
    int spring_break_end = spring_break + 4; //The end of spring break.

    //Prints out the first part of the text.
    printf("Spring Break %d: Monday March %d", year, spring_break);

    //Checks date to see which suffix to add.
    switch(spring_break)
    {
    case(1): //If date is 1st.
             printf("st");
             break;
    case(2): //If date is 2nd.
             printf("nd");
             break;  
    case(3): //If date is 3rd.
             printf("rd");
             break;
    default: //If date is anything else.
             printf("th");
    }

    //Prints out the second part of the text.
    printf(" - Friday March %d", spring_break_end);

    //Checks date to see which suffix to add.
    switch(spring_break_end)
    {
    case(1): //If date is 1st.
             printf("st");
             break;
    case(2): //If date is 2nd.
             printf("nd");
             break;
    case(3): //If date is 3rd.
             printf("rd");
             break;
    default: //If date is anything else.  
             printf("th");
    }
    
    //Additional formatting
    printf("\n");
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayFinal
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year:  The given year.
*       2.int final: The date of the final.
*
*     Function Description: Displays the dates of the finals.
*
***************************************************************************/
void displayFinal(int year, int final)
{
    int final_end = 0;

    printf("Spring %d Finals Exam Week: Monday ", year);

    if (final > 19)
    {
      printf("April ");
    }
    else
    {
      printf("May ");
    }

    printf("%d", final);

    //Checks date to see which suffix to add.
    switch(final)
    {
      case(1): //If date is 1st.
      printf("st");
      break;
      case(2): //If date is 2nd.
      printf("nd");
      break;
      case(3): //If date is 3rd.
      printf("rd");
      break;
      default: //If date is anything else.
      printf("th");
    }
    
    final_end = final + 5;
    
    if (final_end > 30)
    {
      final_end -= 30;
    }

    printf(" - Saturday May %d", final_end);

    //Checks date to see which suffix to add.
    switch(final_end)
    {
      case(1): //If date is 1st.
      printf("st");
      break;
      case(2): //If date is 2nd.
      printf("nd");
      break;                                                                           case(3): //If date is 3rd.
      printf("rd");                                                                    break;                                                                           default: //If date is anything else.
      printf("th");                                                                  }

    printf("\n\n");

    return;
}