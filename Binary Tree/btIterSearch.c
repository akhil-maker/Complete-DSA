#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left, *right;
};
struct Node* newNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct Node* btIterSearch(struct Node* root, int val){
    if(root==NULL)
        return NULL;
    struct Node* p = root;
    while(p!=NULL && p->data!=val){
        if(p->data==val)
            break;
        else if(p->data>val)
            p = p->left;
        else if(root->data<val)
            p = p->right;
    }
    return p;
}
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(3);
    root->right->right = newNode(4);
    root->right->right->right = newNode(5);
    struct Node* t = btIterSearch(root, 5);
    if(t!=NULL)
        printf("present");
}