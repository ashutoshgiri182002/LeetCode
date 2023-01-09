class Solution {
public:
  
   vector<vector<int>>ans;
   
   void helper(int ind, int k,vector<int>&temp){
       
       if(ind==0){
           if(k==0){
               ans.push_back(temp);
           } 
           return;
       }
       
        temp.push_back(ind);
        helper(ind-1,k-1,temp);
        temp.pop_back();
        helper(ind-1,k,temp);
        
       return ;

   }
   
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>temp;

         helper(n,k,temp);
    

      return ans;

    }
};
