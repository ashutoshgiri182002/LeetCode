class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int cnt = 0;
        int n = strs.size();
        int m = strs[0].size();
        
        if(n==1) return 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n-1;j++){
               if(strs[j][i]>strs[j+1][i]){
                   cnt++;
                   break;
               }
            }
        }
          
          return cnt;
    }
};
