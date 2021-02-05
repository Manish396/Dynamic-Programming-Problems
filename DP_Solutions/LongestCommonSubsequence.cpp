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
int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0; i<=x; i++){
        for(int j = 0; j <=y; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}
