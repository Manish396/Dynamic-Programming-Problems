#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int minCoins(int coin[], int M, int V) 
	{
	    int dp[M+1][V+1];
	    for(int i=0; i<V+1; i++){
	        dp[0][i] = INT_MAX-1;
	    }
	    for(int j=1; j<M+1; j++){
	        dp[j][0] = 0;
	    }
	    for(int j=1; j<V+1; j++){
	        if(j%coin[0]==0){
	            dp[1][j] = j/coin[0];
	        }
	        else{
	            dp[1][j] = INT_MAX-1;
	        }
	    }
	    for(int i=2; i<M+1; i++){
	        for(int j=1; j<V+1; j++){
	            if(coin[i-1]<=j){
	                dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i-1]]+1);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    return dp[M][V]==INT_MAX-1 ? -1:dp[M][V];
	} 	  
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, v;
        cin>>v>>m;
        int coins[m];
        for(int i=0; i<m; i++){
            cin>>coins[i];
        }
        Solution ob;
        cout<<ob.minCoins(coins, m, v)<<"\n";
    }
    return 0;
}
