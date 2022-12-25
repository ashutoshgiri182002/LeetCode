class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i = 0;i<queries.size();i++){
            int sum = queries[i];
            int j = 0;
            int temp = 0;
            while(temp<sum and j<nums.size()){
                temp +=nums[j];
                j++;
            }
             
            if(temp>sum)v.push_back(j-1);
            else v.push_back(j);
            j = 0;
        }
        
        return v;
    }
};
