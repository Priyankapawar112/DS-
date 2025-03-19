#include<stdio.h>
int main (){
int a[]={1,2,1,2,2,3,3,4,5,6,6};
int n=11;
int freq;


for (int i=0; i<n; i++){
    if(a[i]==-1){
        continue;
    }
    freq=1;
    for (int j=i+1; j<n; j++){
        if (a[i]==a[j]){
            freq++;
           // printf ("the frequency of %d is %d \n",a[j],freq);
            a[j]=-1;
        }
    }
        printf ("the frequency of %d is %d \n",a[i],freq);
    }
     

    return 0;

}