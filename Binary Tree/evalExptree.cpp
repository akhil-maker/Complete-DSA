#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node* left, *right;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
bool isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}
int solve(Node* t){
    if(t==NULL)
        return 0;
    else{
        if(!isOperator(t->data))
            return int(t->data);
        else{
            int a = solve(t->left);
            int b = solve(t->right);
            switch(t->data){
                case '+':
                    return a+b;
                case '-':
                    return a-b;
                case '*':
                    return a*b;
                case '/':
                    return a/b;
            }
        }
    }
    return 0;
}
int main(){
    Node* root = newNode('+');
    root->left = newNode('*');
    root->left->left = newNode((char)5);
    root->left->right = newNode((char)4);
    root->right = newNode('-');
    root->right->left = newNode((char)100);
    root->right->right = newNode('/');
    root->right->right->left = newNode((char)20);
    root->right->right->right = newNode((char)2);
    cout<<solve(root)<<endl;
}