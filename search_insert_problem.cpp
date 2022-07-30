class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target > nums[nums.size()-1]) return nums.size();
        
        else if(target < nums[0]) return 0;
        
        else{
            
        int low = 0;
        int high = nums.size()-1;
        int mid = (low+high)/2;
        
        while(nums[low] < nums[high]){
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]<target){
                low = mid + 1;
                mid = (low + high)/2;
            }
                
            
            else{
                high = mid;
                mid = (low + high)/2;
            } 
        }
        
         return mid;
        
        }  
       
    }
};
