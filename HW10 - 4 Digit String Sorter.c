#include <stdio.h>
int getinput();//gets input from user
int sortforward(int);//sorts data from largest to smallest
int multidigit(int);//ensures there is more than 1 unique integer
int reversesort(int);//reversed sorted data

int main()
{
  int posnum;//variable to hold input
  int sorted = 0;//used to hold sorted data
  int revsorted = 0;//used to hold reverse sorted data
  int count = 0;//counts the number of iterations through the while loop
  posnum = getinput();//gets input
  printf("\n");//prints new line
  while (sorted - revsorted != 6174)
  {
    sorted = sortforward(posnum);
    revsorted = reversesort(sorted);
    posnum = sorted - revsorted;
    printf("%04d - %04d = %04d\n", sorted, revsorted, posnum);
    count++;
  }
  printf("\nTotal number of subtractions is: %d\n\n",count);
  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:getinput
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.none
*       2.
*       3.
*
*     Function Description:gets valid 4 digit input from the user
*
***************************************************************************/

int getinput()
{
  int input;//input from user
  int passfail = 1;//used to determine if data is valid
  do
  {
    printf("Enter a positive four digit number: ");
    scanf("%d", &input);
    if (input <= 0)
    {
      printf("\nError! Positive four digit numbers only!\n\n");
      passfail = 1;
    }
    else
    {
      passfail = multidigit(input);
    }
   }
  while(passfail != 0);
  return(input);
}
  
/***************************************************************************
*
*     Function Information
*
*     Name of Function:multidigit
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.input - input from the user
*       2.
*       3.
*
*     Function Descriptionetermines if the data is made up of more than 1 unique integer
*
***************************************************************************/

int multidigit (int input)
{
  int temp1;//holds 1's place
  int temp2;//holds 10's place
  int temp3;//holds 100's place
  int temp4;//holds 1000's place
  temp1 = input % 10;
  input = input / 10;
  temp2 = input % 10;
  input = input / 10;
  temp3 = input % 10;
  input = input / 10;
  temp4 = input;
  if ((temp1 == temp2) && (temp2 == temp3) && (temp3 == temp4))
  {
    printf("\nThis process requires at least two unique digits!\n\n");
    return (1);
  }
  else
  {
    return (0);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:sortforward
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int input - user input by the user
*       2.
*       3.
*
*     Function Description:sorts the data in decending order
*
***************************************************************************/

int sortforward(int input)
{
  int num1;//holds 1's place
  int num2;//holds 10's place
  int num3;//holds 100's place
  int num4;//holds 1000's place
  int temp;//used to reverse data
  int sorted;//sorted data
  int i;//loop control for while loop
  num1 = input % 10;
  num2 = (input / 10) % 10;
  num3 = (input / 100) % 10;
  num4 = (input / 1000) % 10;
  for (i = 1; i <= 4; i++)
  {
    if (num1 > num2)
    {
      temp = num1;
      num1 = num2;
      num2 = temp;
    }
    if (num2 > num3)
    {
      temp = num2;
      num2 = num3;
      num3 = temp;
    }
    if (num3 > num4)
    {
      temp = num3;
      num3 = num4;
      num4 = temp;
    }
  }
  sorted = num4 * 1000 + num3 * 100 + num2 * 10 + num1;
  return(sorted);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:reversesort
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int sorted - data sorted in decending order
*       2.
*       3.
*
*     Function Description:reverses sorted data from decending order to ascending order
*
***************************************************************************/

int reversesort (int sorted)
{
  int reverse;//holds reversed data
  int num1;//holds 1's place
  int num2;//holds 10's place
  int num3;//holds 100's place
  int num4;//holds 1000's place
  num1 = sorted % 10;
  num2 = (sorted / 10) % 10;
  num3 = (sorted / 100) % 10;
  num4 = (sorted / 1000) % 10;
  reverse = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
  return(reverse);
}