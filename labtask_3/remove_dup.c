#include <stdio.h>
int main() {
    
    int arr[] = {1, 2, 3, 4, 2, 3, 5};
    int size= 8;
    int brr[size] ;
    int i, j, count=0;
    
    for(  i=0; i<size; i++){
        for( j=0; j<count; j++){

            if ( arr[i] == brr[j]){
                break;
            }
            
        }

        if ( j == count){
            brr[count] = arr[i];
            count++; 
        }
    }

    for ( int i=0; i<count-1; i++){
        printf ("%d     ", brr[i]);
    }
    
    return 0;
}
