class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
  int element = 0;

  for(int x:nums){
    if(cnt==0){
      element = x;
    }
    if(x==element)cnt++;
    else cnt--;
  }
  return element;
    }
};
