#include<bits/stdc++.h> 
using namespace std; 
int maximizeTheCuts(int n, int x, int y, int z); 
int main(){ 
    //taking testcases 
    int t; 
    cin >> t; 
    
    while(t--){ 
        //taking length of line segment 
        int n;
        cin >> n;
        
        //taking types of segments 
        int x,y,z; 
        cin>>x>>y>>z; 
        
        //calling function maximizeTheCuts() 
        cout << maximizeTheCuts (n, x, y, z) << endl; 
    }
    return 0;
}

int maxi(int a, int b, int c){
    if(a>=b)
        return a>=c ? a:c;
    return b>=c ? b:c;
}

//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<n+1; i++){
       int a=0, b=0, c=0;
       if(i-x>=0){
           if(dp[i-x]==0 && i-x>0){
               a = 0;
           }
           else{
               a = 1 + dp[i-x];
           }
       }
       if(i-y>=0){
           if(dp[i-y]==0 && i-y>0){
               b = 0;
           }
           else{
               b = 1 + dp[i-y];
           }
       }
       if(i-z>=0){
           if(dp[i-z]==0 && i-z>0){
               c = 0;
           }
           else{
               c = 1 + dp[i-z];
           }
       }
       dp[i] = maxi(a, b, c);
    }
    return dp[n];
}
