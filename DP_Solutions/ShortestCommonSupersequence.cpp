#include<bits/stdc++.h> 
using namespace std; 
int shortestCommonSupersequence(char* char*, int, int); 
int main()
{
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases 
    cin >> t; 
    
    while(t--){
        //taking string X and Y
        cin >> X >> Y;
        
        //calling function shortestCommon Supersequence () 
        cout << shortestCommonSupersequence(X, Y, strlen (X), strlen (Y) )<< endl; 
    }
    return 0;
}
int dp[101][101];
int lcs(char* X, char* Y, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    else if(X[m-1] == Y[n-1]){
        return dp[m][n] = 1+lcs(X, Y, m-1, n-1);
    }
    else{
        return dp[m][n] = max(lcs(X, Y, m-1, n),lcs(X, Y, m, n-1));
    }
}
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    //code here
    memset(dp, -1, sizeof(dp));
    return m+n-lcs(X, Y, m, n);
}
