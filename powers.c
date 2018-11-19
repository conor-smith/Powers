#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A recursive function which generates an array of differences and
 * reiterates on new array until all numbers are the same*/
int findDiff(int numbers[],int size)
{
    //generates a new array for storing differences in previous array
    int newNumbers[size-1];

    for(int i = 0;i < size-1;i++)
        newNumbers[i] = numbers[i+1] - numbers[i];
    
    //Either returns or reiterates
    if(newNumbers[0] == newNumbers[1])
        return newNumbers[0];
    else
        return findDiff(newNumbers, size-1);
}

int main(int argc, char **argv)
{
    //Stores final output
    int results[10];

    //generates results (max size = 9 because 10^10 > maximum int size)
    for(int i = 1;i <= 9;i++)
    {
        //Generates array {0 ^ i, 1 ^ i...10 ^ i}
        int powers[11];
        for(int j = 0;j <= 10;j++)
            powers[j] = (int) pow(j, i);
        
        //Generates individual results
        results[i-1] = findDiff(powers, 11);
    }

    //prints results to terminal
    for(int i = 0;i < 10;i++)
        printf("%i, ", results[i]);
    printf("\n");
}