#include <stdio.h>

void getInput(int*, char*, int*, char*, int*);
int checkPar(char, char);
int calcTotal(int, int, int, char, char, int);
void printEquation(int, int, int, int, char, char,  int);

int main()
{
    int num1 = 0;   //The first number in the given equation.
    int num2 = 0;   //The second number in the given equation.
    int num3 = 0;   //The third number in the given equation.
    int total = 0;  //The total of the equation.
    char op1 = 'F'; //The first operator in the equation.
    char op2 = 'F'; //The second operator in the equation.
    int chkpar = 0; //The precedence check.

    //Gets the equation from the user.
    getInput(&num1, &op1, &num2, &op2, &num3);
    //Checks which side takes precedence.
    chkpar = checkPar(op1, op2);
    //Calculates the total of the equation.
    total = calcTotal(num1, num2, num3, op1, op2, chkpar);
    //Prints the formatted equation and answer.
    printEquation(num1, num2, num3, total, op1, op2, chkpar);

    return(0);
}

void getInput(int* num1, char* op1, int* num2, char* op2, int* num3)
{
    printf("\nEnter the expression in the form [int char int char int]: ");
    scanf("%d %c %d %c %d", num1, op1, num2, op2, num3);

    return;
}

int checkPar(char op1, char op2)
{
    int chkpar = 0; //Precedence check; right is '1', left or equal is '0'.
    int op1r = 0;   //Operator 1 precedence rank (highest is greatest).
    int op2r = 0;   //Operator 2 precedence rank (highest is greatest).

    //Operator 1 precendece switch.
    switch(op1)
    {
      case '+': //Equal to '-'.
      case '-': op1r = 1;
                break;
      case '*': //Equal to '/'.
      case '/': op1r = 2;
                break;
      case '%': op1r = 3;
    }

    //Operator 2 precedence switch.
    switch(op2) {
      case '+': //Equal to '-'.
      case '-': op2r = 1;
                break;
      case '*': //Equal to '/'.
      case '/': op2r = 2;
                break;
      case '%': op2r = 3;
    }

    //Checks which side of equation has precedence.
    if ((op1r > op2r) || (op1r == op2r))
    {
      //Left side taken precedence or sides are equal in precedence.
      chkpar = 0;
    }
    else if (op1r < op2r)
    {
      //Right side taken precedence.
      chkpar = 1;
    }

    return(chkpar);
}

int calcTotal(int num1, int num2, int num3, char op1, char op2, int chkpar)
{
    int total = 0; //The total of the equation.

    //If precedence lies on the left or precedence is equal.
    if (chkpar == 0)
    {
        //Operator 1 calculation switch; calculation on left done first.
        switch(op1)
        {
          case('+'): total = num1 + num2;
                     break;
          case('-'): total = num1 - num2;
                     break;
          case('*'): total = num1 * num2;
                     break;
          case('/'): total = num1 / num2;
                     break;
          case('%'): total = num1 % num2;
        }

        //Operator 2 calculation switch; remaining number used accordingly.
        switch(op2)
        {
          case('+'): total += num3;
                     break;
          case('-'): total -= num3;
                     break;
          case('*'): total *= num3;
                     break;
          case('/'): total /= num3;
                     break;
          case('%'): total %= num3;
        }
    }
    //If precedence lies on the right.
    else if (chkpar == 1)
    {
        //Operator 2 calculation switch; calculations on right done first.
        switch(op2)
        {
          case('+'): total = num2 + num3;
                     break;
          case('-'): total = num2 - num3;
                     break;
          case('*'): total = num1 * total;
                     break;
          case('/'): total = num1 / total;
                     break;
          case('%'): total = num1 % total;
        }
    }

    return(total);
}

void printEquation(int num1, int num2, int num3, int total, char op1, char op2, int chkpar)
{
    //If precedence lies on the left or precedence is equal.
    if (chkpar == 0)
    {
        printf("(%d %c %d) %c %d = %d\n\n", num1, op1, num2, op2, num3, total);
    }
    //If precedence lies on the right.
    else if (chkpar == 1)
    {
        printf("%d %c (%d %c %d) = %d\n\n", num1, op1, num2, op2, num3, total);
    }

    return;
}