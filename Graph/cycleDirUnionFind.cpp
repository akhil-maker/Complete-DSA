#include<bits/stdc++.h>
using namespace std;
int find(vector<int> parent, int x){
    if(parent[x]==-1)
        return x;
    return find(parent, parent[x]);
}
void Union(int x, int y, vector<int> parent){
    parent[x] = y;
}
bool isCyclic(vector<vector<int>> a){
    vector<int> parent(a.size(), -1);
    vector<vector<int>> visited;
    vector<int> r(a.size(), 0);
    for(int i=0; i<a.size(); i++)
        visited.push_back(r);
    for(int i=0; i<a.size(); i++){
        for(int j=0;  j<a[i].size(); j++){
            if(a[i][j]==1 && visited[i][j]==0){
                int x = find(parent, i);
                int y = find(parent, j);
                cout<<i<<" "<<x<<" "<<j<<" "<<y<<endl;
                if(x==y)
                    return true;
                Union(x, y, parent);
                visited[i][j] = 1;
                visited[j][i] = 1;
                i = j;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> a = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0},
    };
    cout<<isCyclic(a);
}