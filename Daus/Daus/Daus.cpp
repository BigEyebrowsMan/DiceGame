#include "HeaderDaus.h"

//Main function of the program
int main()
{
    
    //Here we state the main variables used during the program
    int opcio = 0;
    int cartera = 100;
    
    //Random seed
    srand(time(0));

    //Function that initates the void that creates the program
    menu(opcio, &cartera);
           
}

