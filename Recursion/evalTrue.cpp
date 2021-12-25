#include<iostream>
using namespace std;
int evalTrue(string s, int i, int j, bool isTrue){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        bool leftT = evalTrue(s, i, k-1, true);
        bool leftF = evalTrue(s, i, k-1, false);
        bool rightT = evalTrue(s, k+1, j, true);
        bool rightF = evalTrue(s, k+1, j,false);
        if(s[k]=='&'){
            if(isTrue==true)
                ans = ans + leftT*rightT;
            else
                ans = ans + leftF*rightT + leftT*rightF + leftF*rightF;
        }
        else if(s[k]=='|'){
            if(isTrue==true)
                ans = ans + leftT*rightF + leftF*rightT + leftT*rightT;
            else
                ans = ans + leftF*rightF;
        }
        else if(s[k]=='^'){
            if(isTrue==true)
                ans = ans + leftF*rightT + leftT*rightF;
            else
                ans = ans + leftT*rightT + leftF*rightF;
        }
    }
    return ans;
}
int main(){
    cout<<evalTrue("T|T&F^T", 0, 6, true);
}