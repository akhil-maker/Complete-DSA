#include<iostream>
using namespace std;
int dp[101][101];
bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++, j--;
    }
    return true;
}
int palPart(string s, int i, int j){
    if(i>=j)
        return 0;
    if(isPalindrome(s, i, j))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mn = INT_MAX, left, right;
    for(int k=i; k<=j-1; k++){
        if(dp[i][k]==-1)
            left = palPart(s, i, k);
        else
            left = dp[i][k];
        if(dp[k+1][j]==-1)
            right = palPart(s, k+1, j);
        else
            right = dp[k+1][j];
        int temp = left + right + 1;
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}
int main(){
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            dp[i][j] = -1;
    cout<<palPart("geek", 0, 3);
}