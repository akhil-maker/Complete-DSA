#include<bits/stdc++.h>
using namespace std;
bool cyclebfs(vector<vector<int>> a){
    int i = 0;
    vector<int> recst(4, 0);
    vector<int> visited(4, 0);
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        i = q.front();
        q.pop();
        recst[i] = 1;
        for(int j=0; j<4; j++){
            if(a[i][j]==1 && visited[j]==0){
                q.push(j);
                visited[j] = 1;
            }
            else if(a[i][j]==1 && recst[j]==1)
                return true;
        }
    }
    return false;
}
bool isCyclic(int i, vector<int> visited, vector<vector<int>> a, vector<int> recst){
    visited[i] = 1;
    recst[i] = 1;
    for(int j=0; j<a[i].size(); j++){
        if(visited[j]==0 && a[i][j]==1 && isCyclic(j, visited, a, recst))
            return true;
        else if(recst[j]==1 && a[i][j]==1)
            return true;
    }
    recst[i] = false;
    return false;
}
bool cycledfs(vector<vector<int>> a){
    vector<int> visited(a.size(), 0);
    vector<int> recst(a.size(), 0);
    for(int u=0; u<a.size(); u++)
        if(isCyclic(u, visited, a, recst))
            return true;
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
    };
    cout<<cyclebfs(a)<<endl;
    cout<<cycledfs(a)<<endl;
}