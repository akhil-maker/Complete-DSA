#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left, *right;
    int height;
};
int getHeight(struct Node* n){
    if(n==NULL)
        return 0;
    return n->height;
}
struct Node* newNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}
int getBF(struct Node* p){
    if(p==NULL)
        return 0;
    return getheight(p->left) - getheight(p->right);
}
struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(getHeight(y->right), getheight(y->left)) + 1;
    x->height = max(getHeight(x->right), getheight(x->left)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(getHeight(x->right), getheight(x->left)) + 1;
    y->height = max(getHeight(y->right), getheight(y->left)) + 1;
    return y;
}
struct Node* insert(struct Node* node, int data){
    if(node==NULL)
        return newNode(data);
    if(data<node->data)
        node->left = insert(node->left, data);
    else if(data>node->data)
        node->right = insert(node->right, data);
        return node;
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBF(node);
    //LL
    if(bf>1 && data<node->left->data){
        
    }
    //RR
    //LR
    //RL
}
int main(){

}