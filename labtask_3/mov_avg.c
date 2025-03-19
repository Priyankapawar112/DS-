#include<stdio.h>
int main() {
   const int n = 12;  
   float a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
   int k = 3;    
   float sum = 0;
   float movAvg = 0;
   for (int i=0; i<2; i++){
    sum = sum + a[i];
    movAvg = sum / (i+1);
    printf(" Moving Average : %.2f \n",movAvg); 

   }
   for (int i = 0; i <= ( n - k); i++) {
     sum = 0;            
     for (int j = i; j < i + k; j++) {
       sum += a[j];        
     }
     movAvg = sum / k;
   printf(" Moving Average : %.2f \n",movAvg); 
   }
   return 0;
}