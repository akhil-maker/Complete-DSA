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
struct Node* btSearch(struct Node* root, int val){
    if(root==NULL)
        return NULL;
    if(root->data==val)
        return root;
    else if(root->data>val)
        return btSearch(root->left, val);
    else if(root->data<val)
        return btSearch(root->right, val);
}
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(3);
    root->right->right = newNode(4);
    root->right->right->right = newNode(5);
    struct Node* t = btSearch(root, 4);
    if(t!=NULL)
        printf("present");
}