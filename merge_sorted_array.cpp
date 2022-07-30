#include<bits/stdc++.h>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
      if(m==0){
        nums1 = nums2;
    }
        
        else{
            
             int i = m-1;
      int j = n-1;
      int k = m+n-1;
        
      while(i>=0 and j>=0){
          if(nums1[i]<=nums2[j]){
              nums1[k] = nums2[j];
              k--;
              j--;
          }
          else{
              nums1[k] = nums1[i];
              nums1[i] =0;
              k--;
              i--;
          
          }
          
        }
            
          if(i<0){
           for(int p = 0;p<=j;p++){
               nums1[p] = nums2[p];
           }
       }
    
    }
        
        
     
        
    }       
};
