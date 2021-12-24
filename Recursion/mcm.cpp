#include<iostream>
using namespace std;
int mcm(int a[], int i, int j){
    if(i>=j)
        return 0;
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempans = mcm(a, i, k) + mcm(a, k+1, j) + a[i-1]*a[k]*a[j];
        if(tempans<mn)
            mn = tempans;
    }
    return mn;
}
int main(){
    int a[] = {40, 20, 30, 10, 30};
    cout<<mcm(a, 1, 4);
}