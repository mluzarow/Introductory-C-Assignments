#include<stdio.h>
#include<math.h>
#define LENGTH 20//length of the array

void getinput(int []);
void sort(int []);
void printvector(int [], int);
void reorderdigits(int []);
void unique(int []);
int zeros(int);
int findmax(int, int*);
int sorting(int, int);
int removeval(int, int, int);


int main()
{
  int startarray[LENGTH];//holds the array input by the user


  getinput(startarray);//get input from the user
  printvector(startarray, 1);//print original array to the screen
  reorderdigits(startarray);//reorders the digits of each number
  printvector(startarray, 2);//prints the re-ordered array
  sort(startarray);//sorts the array in ascending order
  printvector(startarray, 3);//prints the sorted array
  unique(startarray);//determines the number of unique elements in the array

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:getinput
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int startarray[] - array to be input by the user
*       2.
*       3.
*
*     Function Description:accepts input from the user and stores in in a vector of length LENGTH
*
***************************************************************************/

void getinput(int startarray[])
{
  int i;//loop control variable
  for (i = 0; i < LENGTH; i++)
  {
    printf("Enter data #%d: ", i + 1);
    scanf("%d", &startarray[i]);
  }
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
*       1.int startarray [] - vector of integers that have been reordered
*       2.
*       3.
*
*     Function Description:Sorts the data in the vector from smallest to largest.
*
***************************************************************************/

void sort(int startarray[])
{
  int temp;//used to hold first value in order to switch them
  int i;//loop control variable
  for(i = 0; i < LENGTH; i++)
  {
    int lcv;//loop control variable
    for (lcv = LENGTH; lcv > i; lcv--)
    {
      if (startarray[lcv] < startarray[lcv - 1])
      {
        temp = startarray[lcv];
        startarray[lcv] = startarray[lcv - 1];
        startarray[lcv - 1] = temp;
      }
    }
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Functionrintvector
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int startarray[] - array that is to be printed
*       2.int iteration - the number of times this function has been called
*       3.
*
*     Function Descriptionrints the array in four rows of 5 integers as well as what step of the program this array corisponds to
*
***************************************************************************/

void printvector(int startarray[], int iteration)
{
  int i;//loop control variable
  switch (iteration)//case based on the number of times the function has been run
  {
    case 1: printf("\nArray contents (after input):\n\n");
    break;
    case 2: printf("\nArray contents (after re-ordering digits):\n\n");
    break;
    case 3: printf("\nArray contents (after sorting data):\n\n");
    break;
  }

  for (i = 0; i < LENGTH; i = i + 5)
  {
    printf("%d %d %d %d %d\n", startarray[i], startarray[i + 1], startarray[i + 2], startarray[i + 3], startarray[i + 4]);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:reorderdigits
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int startarray[] - array input by the user
*       2.
*       3.
*
*     Function Description:this function sorts each individual value in the array into descending order.
*
***************************************************************************/

void reorderdigits(int startarray[])
{
  int lcv;
  int zero;
  int max;
  int loc;
  int sort;

  for (lcv = 0; lcv < LENGTH; lcv++)
  {
    zero = zeros(startarray[lcv]);
    sort = 0;
    loc = 0;
    while (startarray[lcv] > 0)
    {
     max = findmastartarray [lcv], &loc);
     sort = sorting(sort, max);
     startarray[lcv] = removeval(startarray[lcv], max, loc);
    }
    startarray[lcv] = sort * pow(10, zero);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:unique
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int startarray[] - sorted data and ordered data
*       2.
*       3.
*
*     Function Descriptionetermines the number of unique integers in the data set
*
***************************************************************************/

void unique(int startarray[])
{
  int lcv;// loop control variable
  int count = 0;//holds the number of unique variables
  for (lcv = 0; lcv < LENGTH; lcv++)
  {
    if (startarray[lcv] != startarray[lcv + 1])
    {
      count++;
    }
  }
  printf("\nNumber of unique elements: %d\n\n", count);
}


/***************************************************************************
*
*     Function Information
*
*     Name of Function:sorting
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int sort - number ot be sorted
*       2.int max - maximum value
*       3.
*
*     Function Descriptionuts the number back into ascending order
*
***************************************************************************/

int sorting(int sort, int max)
{
  sort = sort * 10 + max;
  return(sort);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:findmax
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int x - value to find the max
*       2.int *loc - location of max
*       3.
*
*     Function Description:finds the maximum value
*
***************************************************************************/

int findmaint x, int *loc)
{
  int max = 0;//maximum value
  int location = 0;//location of max value
  while(x > 0)
  {
    if(x % 10 > max)
    {
      max = x % 10;
      *loc = location;
    }
    x = x / 10;
    location++;
  }
  return(max);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:zeros
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.num - number to be used
*       2.
*       3.
*
*     Function Description:finds the number of nonleading zeros
*
***************************************************************************/


int zeros(int num)
{
  int count;//counts the number of zeros
  while (num > 0)
  {
    if (num % 10 == 0)
    {
      count++;
    }
    num = num / 10;
  }
  return(num);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.int x - number
*       2.int max - maximum value
*       3.int loc - location of max value
*
*     Function Description:
*
***************************************************************************/

int removeval(int x, int max, int loc)
{
  int temp;
  temp = (x - max * pow(10, loc));
  return(temp);
}