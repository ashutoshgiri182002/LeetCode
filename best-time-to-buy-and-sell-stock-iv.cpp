
//Recursion + Memoisation


class Solution {
public:
    
    int f(vector<int>&prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>>&dp){
        
        if(ind==n or cap==0)return 0; //base case
        
       if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        
        int profit=0;
        
        if(buy ==0){  //we can buy the stock
            profit= max(0 + f(prices,n,ind+1,0,cap,dp) , -prices[ind] + f(prices,n,ind+1,1,cap,dp));
        }
        
        if(buy==1){  //we can sett the stcock
           profit= max(0 + f(prices,n,ind+1,1,cap,dp) , prices[ind] + f(prices,n,ind+1,0,cap-1,dp));
        }
        
        return dp[ind][buy][cap] = profit;
    }
    
    
    
    int maxProfit(int k ,vector<int>& prices) {
        
        int n = prices.size();
        
        // Creating a 3d - dp of size [n][2][3]
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        
        return f(prices,n,0,0,k,dp);
        
    }
};


//Tabulation

class Solution {
public:
    
    int maxProfit(int k , vector<int>& prices) {
        
        int n = prices.size();
        
        // Creating a 3d - dp of size [n][2][3]
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        //base case
        //as dp array initialise with 0 we already taken the base case;
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    
                    if(buy==0){
                        dp[ind][buy][cap] = max(0 + dp[ind+1][0][cap] , -prices[ind] + dp[ind+1][1][cap]);
                    }
                    
                    if(buy==1){
                       dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],prices[ind] + dp[ind+1][0][cap-1]);
                  }
                }
            }
        }
        return dp[0][0][k];
        
    }
};
