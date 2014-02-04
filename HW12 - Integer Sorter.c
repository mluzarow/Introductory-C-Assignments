#include<stdio.h>
#define LENGTH 20

int getinput(int[]);
void printdata(int[], int, int);
void sort(int[], int);
void printmoves(int);
int findmin(int[], int, int);
int checkascend(int[], int);

int main()
{
  int array[LENGTH];
  int length;


  length = getinput(array);
  printdata(array, length, 0);
  sort(array, length);
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
*       1.int array [] - array input by the user
*       2.
*       3.
*
*     Function Description:gets input from the user
*
***************************************************************************/

int getinput(int array[])
{
  int lcv; //loop control variable
  int count = 0; //number of sections used
  for (lcv = 0; lcv < LENGTH; lcv++)
  {
    printf("Enter the data #%d: ", count + 1);
    scanf("%d", &array[lcv]);
    count++;
    if (array[lcv] == -1)
    {
      lcv = LENGTH;
      count--;
    }
  }
  return(count);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Functionrintdata
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int array[] - array input by the user
*       2.int length - length of the array input by the user
*       3.in iteration - number of times this function has run
*
*     Function Descriptionrints data to the screen for ths user
*
***************************************************************************/

void printdata(int array[],int length, int iteration)
{
  int i;//loop control variable
  if (iteration == 0)
  {
    printf("\nCurrent Data: ");
  }
  else
  {
    printf("Array after move #%d: ", iteration);
  }
  for (i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:sort
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.array[] - array input by the user
*       2.length - length of the array input by user
*       3.
*
*     Function Description:sorts the array
*
***************************************************************************/

void sort(int array[], int length)
{
  int lcv1;//loop control vairable
  int lcv2;//loop control vairable
  int lcv3 = 0;//loop control variable
  int temp;//temp variable to hold value
  int loc = 0;//location of temp variable

  while ((!checkascend(array, length)) && lcv3 < length)
  {
    temp = 999999999;//set temp to max value
    for(lcv1 = 0; lcv1 < length; lcv1++)
    {
      if(findmin(array, lcv1, length))
      {
        if(temp > array[lcv1])
        {
          temp = array[lcv1];
          loc = lcv1;
        }
      }
    }
    for(lcv2 = loc; lcv2 < length - 1; lcv2++)
    {
      array[lcv2] = array[lcv2 + 1];
    }
    array[length - 1] = temp;
    printdata(array, length, lcv3 + 1);
    lcv3++;
  }
  printmoves(lcv3);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Functionrintmoves
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.count - number of iterations the loop has gone through
*       2.
*       3.
*
*     Function Descriptionrints the number of moves to the screen
*
***************************************************************************/

void printmoves(int count)
{
  printf("\nNumber of moves: %d\n", count);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:findmin
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int array[] - array input by user
*       2.int lcv - loop control variable from previous function
*       3.int length - length of the array
*
*     Function Description:finds the minimum value
*
***************************************************************************/

int findmin(int array[], int lcv, int length)
{
  int i = lcv;//new loop control variable
  int torf = 0;//sets value initially to false
  while ((i < length) && (torf != 1))
  {
    if(array[lcv] > array[i])
    {
      torf = 1;
    }
    i++;
  }
  return(torf);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:checkascend
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int array[] array input by the user
*       2.in tlength - length of array
*       3.
*
*     Function Description:
*
***************************************************************************/

int checkascend(int array[], int length)
{
  int i;//loop control variable
  int result = 1;//sets result to true
  for(i = 0; i < length - 1; i++)
  {
    if(array[i] > array[i + 1])
    {
      result = 0;
    }
  }
  return(result);
}