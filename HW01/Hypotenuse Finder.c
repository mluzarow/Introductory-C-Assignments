#include <stdio.h>
#include <math.h>     //math.h included for use of "pow" command.

int main()
{
    int side_a = 0;   //Side "a", or "Side #2",  of triangle.
    int side_b = 0;   //Side "b", or "Side #1",  of triangle.
    int side_c = 0;   //Side "c", or "Hypotenuse", of triangle.
    int input_m = 0;  //First positive integer value.
    int input_n = 0;  //Second positive integer value.

    //Prompts user for for first and second positive integer values "input_m" and "input_n" respectively.
    printf("Enter the first positive integer value: ");
    scanf("%d", &input_m);
    printf("Enter the second positive integer value (less than %d): ", input_m);
    scanf("%d", &input_n);

    //Computes Side #1, Side #2, and Hypotenuse "side_a", "side_b" and "side_c" respectively using given formulas.
    side_a = (pow(input_m, 2) - pow(input_n, 2));
    side_b = (2 * input_m * input_n);
    side_c = (pow(input_m, 2) + pow(input_n, 2));

    //Prints out inputs and calculated outputs based on given template.
    printf("The Pythagorean triple given positive integers [%d and %d]: ", input_m, input_n);
    printf("\nSide #1:%9.d", side_a);
    printf("\nSide #2:%9.d", side_b);
    printf("\nHypotenuse:%6.d\n", side_c);

    //Returns 0; end program.
    return(0);
}
