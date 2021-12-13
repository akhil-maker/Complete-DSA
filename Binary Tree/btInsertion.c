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
void btInsertion(struct Node* root, int val){
    struct Node* prev;
    while(root!=NULL){
        prev = root;
        if(root->data==val)
            return;
        else if(root->data>val)
            root = root->left;
        else if(root->data<val)
            root = root->right;
    }
    struct Node* ptr = newNode(val);
    if(val<prev->data)
        prev->left = ptr;
    else if(val>prev->data)
        prev->right = ptr;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(3);
    root->right->right = newNode(4);
    root->right->right->right = newNode(5);
    btInsertion(root, 6);
    inorder(root);
    printf("\n");
    btInsertion(root, 2);
    inorder(root);
    printf("\n");
}