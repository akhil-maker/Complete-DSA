#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int mid, int low, int high){
    int i, j, k;
    i = low, j = mid+1, k = low;
    int b[100];
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k] = a[i];
            k++, i++;
        }
        else{
            b[k] = a[j];
            k++, j++;
        }
    }
    while(i<=mid){
        b[k] = a[i];
        k++, i++;
    }
    while(j<=high){
        b[k] = a[j];
        k++, j++;
    }
    for(int i=low; i<=high; i++)
        a[i] = b[i];
}
void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, mid, low, high);
    }
}
int main(){
    int a[] = {9, 14, 4, 8, 7, 5, 6};
    mergeSort(a, 0, 6);
    for(int i=0; i<7; i++)
        printf("%d ", a[i]);
}