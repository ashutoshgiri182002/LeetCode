//by dp and memoisation

class Solution {
public:
    
    int f(int ind , int prev_ind , vector<int>&nums, vector<vector<int>>&dp){
        
        if(ind==nums.size())return 0;
        
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        
        int len = 0 + f(ind+1 ,prev_ind , nums,dp);
        
        if(prev_ind==-1 or nums[ind] > nums[prev_ind]){
            len = max(len, 1 + f(ind+1, ind , nums,dp));
        }
        
        return dp[ind][prev_ind+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1, -1));
        return f(0 , -1, nums,dp);
        
    }
};


//Tabulation method 

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, 0));
        
        //base case is already cover since dp initailise with 0
        
        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind==-1 or nums[ind]> nums[prev_ind]){
                    len = max(len , 1 + dp[ind+1][ind+1]);
                }
                
                dp[ind][prev_ind+1] = len;
            }
            
        }
        
        return dp[0][-1 + 1];
        
    }
};



//Simple DP Solution  --> Memoisation because     TC ->O(N*N), SC -> O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev < i;prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i],1 + dp[prev]);
                }
            }
            
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};
