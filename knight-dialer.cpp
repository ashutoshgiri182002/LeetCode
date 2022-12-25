class Solution {
public:
    
    int m = 1000000007;
    long long solve(int n,int d,vector<vector<long long>>&dp){

        if(d==0) return 1;
        if(dp[n][d]!=-1) return dp[n][d];

        switch(n){
            case 0: return dp[n][d] = solve(4,d-1,dp)%m + solve(6,d-1,dp)%m;
            case 1: return dp[n][d] = solve(8,d-1,dp)%m + solve(6,d-1,dp)%m;
            case 2: return dp[n][d] = solve(9,d-1,dp)%m + solve(7,d-1,dp)%m;
            case 3: return dp[n][d] = solve(4,d-1,dp)%m + solve(8,d-1,dp)%m;
            case 4: return dp[n][d] = solve(3,d-1,dp)%m + solve(9,d-1,dp)%m + solve(0,d-1,dp)%m;
            case 5: return dp[n][d] = 1%m;
            case 6: return dp[n][d] = solve(7,d-1,dp)%m + solve(1,d-1,dp)%m + solve(0,d-1,dp)%m;
            case 7: return dp[n][d] = solve(2,d-1,dp)%m + solve(6,d-1,dp)%m;
            case 8: return dp[n][d] = solve(3,d-1,dp)%m + solve(1,d-1,dp)%m;
            case 9: return dp[n][d] = solve(2,d-1,dp)%m + solve(4,d-1,dp)%m;

        }
        
         return 0;
    }

    int knightDialer(int n) {
        
        int d = n;
        long long sum = 0;
        if(n==1) return 10;
       vector<vector<long long>>dp(10,vector<long long>(d,-1));
        for(int i = 0;i<=9;i++){
           sum += solve(i,n-1,dp);
        }
        return (sum-1)%m;

    }
};
