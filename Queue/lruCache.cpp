#include<bits/stdc++.h>
using namespace std;
class LRUcache
{
    private:
    queue<int> q;
    unordered_map<int, queue<int>> m;
    int capacity;
    public:
    LRUcache(int cap){
        capacity = cap;
    }
    int get(int key){
        if(!m[key].empty()){
            int val = m[key].front();
            return val;
        }
        else
            return -1;
    }
    void set(int key, int value){
        if(q.size()==capacity){
            int x = q.front();
            m[x].pop();
            q.pop();
        }
        q.push(key);
        m[key].push(value);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int capacity;
        cin>>capacity;
        LRUcache* cache = new LRUcache(capacity);
        int queries;
        cin>>queries;
        while(queries--){
            string q;
            cin>>q;
            if(q=="SET"){
                int key;
                cin>>key;
                int value;
                cin>>value;
                cache->set(key, value);
            }
            else{
                int key;
                cin>>key;
                cout<<cache->get(key)<<" ";
            }
        }
        cout<<endl;
    }
}