#include<iostream>
using namespace std;
int rodCutting(int price[], int n, int cost){
    int t[n+1][cost+1];
    int length[n];
    for(int i=0; i<n; i++)
        length[i] = i+1;
    for(int i=0; i<n+1; i++)
        for(int j=0; j<cost+1; j++)
            if(i==0 || j==0)
                t[i][j] = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<cost+1; j++){
            if(i<=j)
                t[i][j] = max(price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][cost];
}
int main(){
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<rodCutting(price, 8, 8);
}