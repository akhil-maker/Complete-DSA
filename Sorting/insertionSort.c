#include<stdio.h>
#include<stdlib.h>
void insertionSort(int a[], int n){
    for(int i=1; i<=n-1; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int a[] = {17, 54, 65, 7, 23, 9};
    insertionSort(a, 6);
    for(int i=0; i<6; i++)
        printf("%d ", a[i]);
}