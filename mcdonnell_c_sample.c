
/*
 *  Sample program for school
 * 
 */

#include <stdio.h>

const float TAX_RATE = 0.06;  // set const tax rate

/* prototypes */
float computeTotal(float* items, int numOfitems);
float computeTax(float total);

int main(){
    int i, numOfItems = 0; // i for for-loop; numOfItems to set array size
    float currentPrice, total, tax; // currentPrice is a placeholder to check if the value is not above $10
    char welcomeMessage[] = {"Welcome to Hansen's Discount Supermarket!\n"};  // A character array to store the welcome message

    // Prompt the user to enter how many items they have to total.
    printf(welcomeMessage);
    printf("How many items do you have to scan: ");

    scanf("%d", &numOfItems);

    // An array with a float datatype to store the prices of the items (should probably bound this to a max # of items)
    float items[numOfItems];

    printf("\nWe are sorry the scanner is broke at the moment.");
    printf("\nPlease enter your prices manually.\n");

    // Use a for() statement to fill the array using the value the user entered as the end point of the loop.
    for(i=0; i<numOfItems; i++){
        printf("\nWhat is the price of your product: ");
        scanf("%f", &currentPrice);
        if(currentPrice < 10.00){
            items[i] = currentPrice;
        }else{
            printf("Invalid Price, Be sure to enter a Price under $10.00\n");
            /*
             * There is a constraint - if the price of any one item is greater than $10.00 it is considered invalid,
             * you must use a repetitive statement to display a message and force the user to enter a value less than $10.00
             *
             * If the check fails set the loop counter back one and repeat (decrement the loop)
             */
            i--;
        }
    }
    
    
    // call functions
    total = computeTotal(items, numOfItems);
    tax = computeTax(total);

    // display results
    printf("\nYour total is %.2f\n", total);
    printf("Tax: %.2f\n", tax);
    printf("\nYour Grand Total including Tax is: %.2f\n", total + tax);
    printf("Have a great day!\n");

    return 0;
}

/*
 * doesn't really need to be a function but reduces main a bit
 */
float computeTotal(float* items, int numOfItems){
    int i; // for C99 outside for loop declaration
    float total = 0;
    for(i=0; i < numOfItems; i++){
        // Use an accumulating total statement to compute the total sales
        total = total + items[i]; // could do total +=  items[i]
    }
    return total;
}

/*
 * create a function to compute the final total using a sales tax of 6% (.06)
 */
float computeTax(float total){
    return total * TAX_RATE;
}
