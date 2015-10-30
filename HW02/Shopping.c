#include <stdio.h>

int main() {
    int tv = 0;         //Stores amount of televisions.
    int br_player = 0;  //Stores amount of Blu-ray players.
    int remote = 0;     //Stores amount of remote controls.
    int mp3_player = 0; //Stores amount of MP3 players.
    int laptop = 0;     //Stores amount of laptops.
    const float TV = 599.99;         //Sets price of television.
    const float BR_PLAYER = 199.99;  //Sets price of Blu-ray player.
    const float REMOTE = 29.99;      //Sets price of remote control.
    const float MP3_PLAYER = 44.99;  //Sets price of MP3 player.
    const float LAPTOP = 349.99;     //Sets price of laptop.

    //Gathers the amount of televisions the user wishes to buy.
    printf("\nEnter the quantity of televisions: ");
    scanf("%d", &tv);
    //Gathers the amount of Blu-ray players the user wishes to buy.
    printf("Enter the quantity of Blu-ray players: ");
    scanf("%d", &br_player);
    //Gathers the amount of remote controls the user wishes to buy.
    printf("Enter the quantity of remote controls: ");
    scanf("%d", &remote);
    //Gathers the amount of MP3 players the user wishes to buy.
    printf("Enter the quantity of MP3 players: ");
    scanf("%d", &mp3_player);
    //Gathers the amount of laptops the user wishes to buy.
    printf("Enter the quantity of laptops: ");
    scanf("%d", &laptop);

    //Prints part of text frame.
    printf("\nQTY  DESCRIPTION      UNIT PRICE  TOTAL PRICE");
    printf("\n---  -----------      ----------  -----------");

    //Prints quantities and their prices according to the frame.
    printf("\n%3d  Television%c      $%9.2f  $%10.2f", tv, tv == 1 ? ' ' : 's', TV, TV * tv);
    printf("\n%3d  Blu-ray Player%c  $%9.2f  $%10.2f", br_player, br_player == 1 ? ' ' : 's', BR_PLAYER, BR_PLAYER * br_player);
    printf("\n%3d  Remote Control%c  $%9.2f  $%10.2f", remote, remote == 1 ? ' ' : 's', REMOTE, REMOTE * remote);
    printf("\n%3d  MP3 Player%c      $%9.2f  $%10.2f", mp3_player, mp3_player == 1 ? ' ' : 's', MP3_PLAYER, MP3_PLAYER * mp3_player);
    printf("\n%3d  Laptop Computer%c $%9.2f  $%10.2f", laptop, laptop == 1 ? ' ' : 's', LAPTOP, LAPTOP * laptop);

    //Prints part of the text frame.
    printf("\n                                  -----------");

    //Prints the calculated price totals with and without tax (7%) according to the text frame.
    printf("\n                        Subtotal  $%10.2f", TV*tv + BR_PLAYER*br_player + REMOTE*remote + MP3_PLAYER*mp3_player + LAPTOP*laptop);
    printf("\n                             Tax  $%10.2f", (BR_PLAYER*br_player + REMOTE*remote + MP3_PLAYER*mp3_player + LAPTOP*laptop) * .07);
    printf("\n                           Total  $%10.2f", (BR_PLAYER*br_player + REMOTE*remote + MP3_PLAYER*mp3_player + LAPTOP*laptop) * 1.07);
    printf("\n");

    return(0);
} //main
