#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
};
struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void verticalTraversal(Node* root){
    map<int, vector<int>> m;
    int hd = 0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, hd));
    while(!q.empty()){
        pair<Node*, int> t = q.front();
        q.pop();
        hd = t.second;
        Node* node = t.first;
        m[hd].push_back(node->data);
        if(node->left!=NULL)
            q.push(make_pair(node->left, hd-1));
        if(node->right!=NULL)
            q.push(make_pair(node->right, hd+1));
    }
    map<int, vector<int>>::iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}
int main(){
    Node* root = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    verticalTraversal(root);
}