#include<iostream>
#include<queue>
using namespace std;
class Solution{
    public:
    string FirstNonRepeating(string a){
        queue<char> q;
        int count[26] = {0};
        string r = "";
        for(int i=0; i<a.length(); i++){
            q.push(a[i]);
            count[a[i]-'a']++;
            while(!q.empty()){
                if(count[q.front()-'a']>1)
                    q.pop();
                else{
                    r += q.front();
                    break;
                }
            }
            if(q.empty())
                r += '#';
        }
        return r;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        Solution obj;
        string ans = obj.FirstNonRepeating(a);
        cout<<ans<<endl;
    }
    return 0;
}