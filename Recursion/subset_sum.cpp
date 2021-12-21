#include<iostream>
using namespace std;
bool subsum(int a[], int sum, int n){
    if(n==0 && sum!=0)
        return false;
    if(sum==0)
        return true;
    else if(a[n-1]<=sum)
        return subsum(a, sum-a[n-1], n-1) || subsum(a, sum, n-1);
    else
        return subsum(a, sum, n-1);
}
int main(){
    int a[] = {2, 3, 7, 8, 10};
    cout<<subsum(a, 11, 5);
}