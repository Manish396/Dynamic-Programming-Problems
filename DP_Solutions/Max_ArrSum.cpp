#include <bits/stdc++.h>
using namespace std;

long long int maxi(long long int a, long long int b, long long int c){
    if(a>=b){
        if(a>=c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else{
            return c;
        }
    }
}
// Complete the maxSubsetSum function below.
long maxSubsetSum(vector<int> arr) {
    long l = arr.size();
    long long int dp[l+1];
    dp[0] = 0;
    dp[1] = arr[0];
    dp[2] = max(arr[1], arr[0]);
    for(int i=3; i<l+1; i++){
        dp[i] = maxi(dp[i-2]+arr[i-1], dp[i-1],arr[i-1]);
    }
    return dp[l];
}

int main()
{
    int num;
    cin>>num;
    vector<int>v(num);
    for(int i=0; i<num; i++){
        cin>>v[i];
    }
    cout<<maxSubsetSum(v)<<endl;
    return 0;
}
