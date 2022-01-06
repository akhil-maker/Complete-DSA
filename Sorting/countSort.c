#include<stdio.h>
#include<stdlib.h>
int maximum(int a[], int n){
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i]>mx)
            mx = a[i];
    }
    return mx;
}
void countSort(int a[], int n){
    int mx = maximum(a, n);
    int* cnt = (int*)malloc((mx+1)*sizeof(int));
    for(int i=0; i<mx+1; i++)
        cnt[i] = 0;
    for(int i=0; i<n; i++)
        cnt[a[i]] = cnt[a[i]]+1;
    int k = 0;
    for(int i=0; i<mx+1; i++){
        while(cnt[i]--){
            a[k] = i;
            k++;
        }
    }
}
int main(){
    int a[] = {9, 1, 4, 14, 4, 15, 6};
    countSort(a, 7);
    for(int i=0; i<7; i++)
        printf("%d ", a[i]);
}