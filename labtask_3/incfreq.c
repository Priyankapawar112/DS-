#include<stdio.h>
void printarray(int* a, int n){
    for (int i=0; i<n; i++){
        printf("%d  ",a[i]);
    }
}

void bubblesort(int* a, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (a[j]>=a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return;
}
int main(){
    int a[]={1,2,1,2,2,3,3,4,5,6,6};
    int n=11;
    bubblesort(a, n);
    printarray(a, n);

    return 0;
}