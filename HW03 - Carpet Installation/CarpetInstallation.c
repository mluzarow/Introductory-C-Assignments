#include <stdio.h>

//Prototypes go here
void getInput(int*, int*, int*, float*);
float calcInstalledPrice(int, int, float);
float calcSubtotal(float, int);
float calcTotal(float);
void printMeasure(int, int);
void printCharges(int, int, float, float, int, float, float);

int main() {
    int length = 0;         //The length of the room (ft).
    int width = 0;          //The width of the room (ft).
    int discount = 0;       //The discount the user has (%).
    float costSF = 0;       //The cost per square foot ($/ft^2).
    float installPrice = 0; //The price of installation ($).
    float subtotal = 0;     //The subtotal of purchase ($).
    float total = 0;        //The total of purchase ($).

    //Gets the input from the user.
    getInput(&length, &width, &discount, &costSF);
    //Calculates the installation price.
    installPrice = calcInstalledPrice(length, width, costSF);
    //Calculates the subtotal.
    subtotal = calcSubtotal(installPrice, discount);
    //Calculates the total cost.
    total = calcTotal(subtotal);
    //Prints the measurements section.
    printMeasure(length, width);
    //Prints the charges section.
    printCharges(length, width, costSF, installPrice, discount, subtotal, total);

    return(0);
}

//Gets carpet dimensions from the user
void getInput(int* length, int* width, int* discount, float* costSF) {
    printf("\nEnter the length of the room (in ft): ");
    scanf("%d", length);
    printf("Enter the width of the room (in ft): ");
    scanf("%d", width);
    printf("Enter the customer discount (a percent value from 0 to 100): ");
    scanf("%d", discount);
    printf("Enter the cost per square foot: ");
    scanf("%f", costSF);
    
    return;
}

//Calculates price of carpet installation
float calcInstalledPrice(int length, int width, float costSF) {
    float installPrice = 0;  //Price of installation.
    installPrice = ((length * width) * costSF)+ ((length * width)*0.35);

    return(installPrice);
}

//Calculates price with discount
float calcSubtotal(float installPrice, int discount) {
    float subtotal = 0;  //Subtotal cost.
    subtotal = installPrice - (installPrice * ((float) discount / 100));

    return(subtotal);
}

//Calculates total price
float calcTotal(float subtotal) {
    float total = 0;  //Total cost.
    total = subtotal + (subtotal * .085);

    return(total);
}

//Prints user dimensions
void printMeasure(int length, int width) {
    printf("\n            MEASUREMENT\n");
    printf("Length%25.0d ft", length);
    printf("\nWidth %25.0d ft", width);
    printf("\nArea  %25.0d square ft", length * width);

    return;
}

//Prints carpet installation receipt
void printCharges(int length, int width, float costSF, float installPrice, int discount, float subtotal, float total) {
    printf("\n\n              CHARGES\n");
    printf("\nDESCRIPTION  COST/SQ.FT.      CHARGE");
    printf("\n-----------  -----------  ----------");
    printf("\nCarpet       $%10.2f  $%9.2f", costSF, costSF * (length * width));
    printf("\nLabor        $%10.2f  $%9.2f", 0.35, 0.35 * (length * width));
    printf("\n                          ----------");
    printf("\nINSTALL PRICE             $%9.2f", installPrice);
    printf("\nDiscount%15d%%  $%9.2f", discount, ((float) discount / 100) * installPrice);
    printf("\nSUBTOTAL                  $%9.2f", subtotal);
    printf("\nTax                       $%9.2f", subtotal * 0.085);
    printf("\nTOTAL                     $%9.2f\n\n", total);

    return;
}
