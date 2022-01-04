#include<stdio.h>
#include<stdlib.h>
void selectionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int indOfmin = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[indOfmin])
                indOfmin = j;
        }
        int temp = a[i];
        a[i] = a[indOfmin];
        a[indOfmin] = temp;
    }
}
int main(){
    int a[] = {8, 0, 7, 1, 3};
    selectionSort(a, 5);
    for(int i=0; i<5; i++)
        printf("%d ", a[i]);
}