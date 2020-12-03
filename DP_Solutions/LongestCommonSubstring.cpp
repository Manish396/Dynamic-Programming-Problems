#include<iostream>
using namespace std;
int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0; i<x+1; i++){
        dp[i][0]=0;
    }
    for(int i=0; i<y+1; i++){
        dp[0][i] = 0;
    }
    int maxi=0;
    for(int i=1; i<x+1; i++){
        for(int j=1; j<y+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                if(dp[i][j]>maxi){
                    maxi = dp[i][j];
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--){
	    int x, y;
	    cin >> x >> y;
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout <<lcs(x, y, s1, s2) <<"\n";
	}
	return 0;
}
