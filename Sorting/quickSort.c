#include<stdio.h>
#include<stdlib.h>
int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1;
    int j = high;
    do{
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    while(i<j);
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quickSort(int a[], int low, int high){
    int pIndex;
    if(low<high){
        pIndex = partition(a, low, high);
        quickSort(a, low, pIndex-1);
        quickSort(a, pIndex+1, high);
    }
}
int main(){
    int a[] = {3, 5, 2, 12, 13};
    quickSort(a, 0, 4);
    for(int i=0; i<5; i++)
        printf("%d ", a[i]);
}