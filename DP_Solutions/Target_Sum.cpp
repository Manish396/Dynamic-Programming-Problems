class Solution {
public:
    int count_Subset(vector<int>&nums, int sum){
        int n = nums.size();
        int dp[n+1][sum+1];
        for(int i=0; i<sum+1; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]==0){
                    dp[i][j] = dp[i-1][j];
                }
                else if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, long S) {
        long sumArray = 0,count=0;
        for(auto each : nums){
            sumArray += each;
            if(each == 0){
                count++;
            }
        }
        if(S>sumArray || (sumArray-S)%2==1)
             return 0;
        long sum = (S + sumArray)/2;
        return count_Subset(nums, sum)*pow(2,count);
    }
};
