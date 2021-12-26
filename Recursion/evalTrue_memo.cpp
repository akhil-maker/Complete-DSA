#include<iostream>
using namespace std;
int dp[101][101][2];
int evalTrue(string s, int i, int j, bool isTrue){
    if(i>j)
        return false;
    if(i==j){
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];
    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        int leftT = evalTrue(s, i, k-1, true);
        int leftF = evalTrue(s, i, k-1, false);
        int rightT = evalTrue(s, k+1, j, true);
        int rightF = evalTrue(s, k+1, j, false);
        if(s[k]=='&'){
            if(isTrue==true)
                ans += leftT*rightT;
            else
                ans += leftF*rightT + leftT*rightF + leftF*rightF;
        }
        else if(s[k]=='|'){
            if(isTrue==true)
                ans += leftF*rightT + leftT*rightF + leftT*rightT;
            else
                ans += leftF*rightF;
        }
        else if(s[k]=='^'){
            if(isTrue==true)
                ans += leftT*rightF + leftF*rightT;
            else    
                ans += leftF*rightF + leftT*rightF;
        }
    }
    return dp[i][j][isTrue] = ans;
}
int main(){
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            for(int k=0; k<2; k++)
                dp[i][j][k] = -1;
    string sym = "TTFT";
    string opr = "|&^";
    string s;
    int j = 0;
    for(int i=0; i<sym.length(); i++){
        s.push_back(sym[i]);
        if(j<opr.length())
            s.push_back(opr[j++]);
    }
    cout<<evalTrue(s, 0, s.length()-1, true);
}