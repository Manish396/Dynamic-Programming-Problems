#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;

int lcs(int , int, string , string);

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        
        string s1, s2;
        cin >> s1 >> s2;
        
        cout << lcs(x, y, s1, s2) <<"\n";
    }
    return 0;
}
// function to find longest common subsequence
int  dp[101][101];
int lcs(int x, int y, string s1, string s2){
    
    // your code here
    if(x==s1.size() && y==s2.size()){
        memset(dp, -1, sizeof(dp));
    }
    if(x==0 || y==0){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else if(s1[x-1] == s2[y-1]){
        return dp[x][y] = 1+lcs(x-1, y-1, s1, s2);
    }
    else{
        return dp[x][y] = max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
    }
}
