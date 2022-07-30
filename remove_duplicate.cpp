class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i =0;
        int j =1;
        int cnt =1;
        while(j < nums.size()){
            if(nums[i]==nums[j]){
                
                j++;
            }
            
            else{
                 i++;
                cnt++;
                nums[i] = nums[j];
               
            }
            
        }
        
        return cnt ;
    }
};
