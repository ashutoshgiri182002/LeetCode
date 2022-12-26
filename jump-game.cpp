class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = -1;
        int i = 0;
        while(maxi!=0 and i<n){
            maxi = max(maxi-1,nums[i]);
            i++;
        }
     
     if(i==n) return true;
     return false;
 
    }
    
};
