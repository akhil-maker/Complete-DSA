#include<iostream>
using namespace std;
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
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp = palPart(s, i, k)+palPart(s, k+1, j)+1;
        mn = min(mn, temp);
    }
    return mn;
}
int main(){
    cout<<palPart("abcde", 0, 4);
}