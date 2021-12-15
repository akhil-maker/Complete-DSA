#include<bits/stdc++.h>
using namespace std;
struct Node{
    int  data;
    Node* left, *right;
};
Node* newNode(int data){
    Node* p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
vector<Node*> getTrees(int a[], int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> ltrees = getTrees(a, start, i-1);
        vector<Node*> rtrees = getTrees(a, i+1, end);
        for(int j=0; j<ltrees.size(); j++){
            for(int k=0; k<rtrees.size(); k++){
                Node* node = newNode(a[i]);
                node->left = ltrees[j];
                node->right = rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int in[] = {1, 2, 3, 4, 5};
    int n = 5;
    vector<Node*> trees = getTrees(in, 0, n-1);
    for(int i=0; i<trees.size(); i++){
        preorder(trees[i]);
        cout<<endl;
    }
}