#include <stdio.h>
#include <math.h>
//Going any higher than 15 results in a seg fault
#define nof 15
#define noof nof-2

/* Allows for multiple functions to write to the same file
 * because global variables are easier than passing them down*/
FILE *store;

/* A recursive function which generates an array of differences and
 * reiterates on new array until all numbers are the same*/
double findDiff(double numbers[], int size)
{
    //generates a new array for storing differences in previous array
    double newNumbers[size-1];

    for(int i = 0;i < size-1;i++)
        newNumbers[i] = numbers[i+1] - numbers[i];
    
    //Prints to text file
    for(int i = 0;i < size-1;i++)
        fprintf(store, "%.0f, ", newNumbers[i]);
    fprintf(store, "\n");

    //Either returns or reiterates
    if(newNumbers[0] == newNumbers[1])
        return newNumbers[0];
    else
        return findDiff(newNumbers, size-1);
}

int main()
{
    //Stores final output
    double results[noof+1];

    //Initializes file
    store = fopen("results.txt", "w");

    //generates results
    for(int i = 1;i <= noof;i++)
    {
        //Generates array {0 ^ i, 1 ^ i...10 ^ i}
        double powers[nof];
        for(int j = 0;j < nof;j++)
            powers[j] = pow(j, i);
        
        //Generates individual results + prints current iteration to file
        fprintf(store, "Pattern for x ^ %i\n", i);
        for(int j = 0;j < nof;j++)
            fprintf(store, "%.0f, ", powers[j]);
        fprintf(store, "\n");
        results[i-1] = findDiff(powers, nof);
        fprintf(store, "\n");
    }

    //closes file
    fclose(store);

    //prints results to terminal
    for(int i = 0;i < noof;i++)
        printf("%.0f, ", results[i]);
    printf("\n");
}