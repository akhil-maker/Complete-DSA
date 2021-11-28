#include<stdio.h>
void display(int a[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int indDeletion(int a[], int size, int index){
    for(int i=index; i<size-1; i++){
        a[i] = a[i+1];
    }
    size -= 1;
    return size;
}
int main(){
    int a[1000] = {5, 2, 3, 6, 7};
    int size = 5, index = 1;
    display(a, size);
    size = indDeletion(a, size, index);
    display(a, size);
    return 0;
}