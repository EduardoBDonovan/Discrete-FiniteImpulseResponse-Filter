/*
 * Averge.c
 *
 *  Created on: Nov 24, 2020
 *      Author: eddiedonovan
 */

#include <stdio.h>
#define SIZE 1000

double b(int N) //bi
{
    return 1.0 / (N+1.0) ;
}

double y(double* x, int n, int N, int counter) {
    printf ("%d\n", N) ;
    if (counter == N || n ==0)
    {
        return b(N) * x[n] ;
    }
    else if (n <= N && counter == 0)
    {
        return 0 ;
    }
    else
    {
        return b(N) * x[n] + y(x, n-1, N, counter + 1) ;
    }
}

int main(void)
{
     FILE *fPtr;
     FILE *fOut;
     int i = 0;
     int counter = 0;
     double sample[SIZE];

     fOut=fopen("filter.dat","w");
     if(fOut==NULL){
         printf("File cannot be opened");
     }
     // fopen opens file; exits program if file cannot be opened
     if ((fPtr = fopen("signal.dat", "r")) == NULL) {
           puts("File could not be opened");
     }
     else {

           // while not end of file
           while (!feof(fPtr)) {
                fscanf(fPtr, "%lf", &sample[i]);
                //printf("%7.3f\n", sample);
                //fprintf(fOut,"%7.3f\n",sample);
                i ++ ;
           }
           fclose(fPtr); // fclose closes the file

     }
     fPtr = fopen ("filter.dat", "w");
     for (int g = 0 ; g < i ; g++) {
        fprintf (fOut, "%20d\t%20lf\t%20lf\t%20lf\n", g, sample[g], y(sample, g+5, 10, counter), y(sample, g+50, 100, counter)) ;
                    }
     fclose(fPtr);
     fclose(fOut);
}

