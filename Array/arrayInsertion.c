#include<stdio.h>
#include<stdlib.h>
struct myArr{
    int tsize;
    int usize;
    int *ptr;
};
void createArr(struct myArr* a, int total, int used){
    a->tsize = total;
    a->usize = used;
    a->ptr = (int*)malloc(total*sizeof(int));
}
void setVal(struct myArr* a){
    int n;
    for(int i=0; i<a->usize; i++){
        printf("Enter the element at %d position: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
void show(struct myArr* a){
    printf("Display elements of array:");
    for(int i=0; i<a->usize; i++)
        printf("%d ", (a->ptr)[i]);
}
int main(){
    struct myArr a;
    createArr(&a, 10, 3);
    setVal(&a);
    show(&a);
    return 0;
}