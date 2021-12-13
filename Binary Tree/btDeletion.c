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
struct Node* inorderPre(struct Node* root){
    root = root->left;
    while(root->right!=NULL)
        root = root->right;
    return root;
}
struct Node* btDeletion(struct Node* root, int val){
    struct Node* ipre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //Search for deletion of node
    if(val<root->data)
        root->left = btDeletion(root->left, val);
    else if(val>root->data)
        root->right = btDeletion(root->right, val);
    //Deletion strategy
    else{
        ipre = inorderPre(root);
        root->data = ipre->data;
        root->left = btDeletion(root->left, ipre->data);
    }
    return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main(){
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    btDeletion(root, 5);
    inorder(root);
}