class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int maxr) {
        
        vector<int>sub;
        int n = capacity.size();

        for(int i = 0;i<n;i++){
            sub.push_back(capacity[i] - rocks[i]);
        }
      
      sort(sub.begin(),sub.end());
       int i = 0;
       while(maxr>0 and i<n){
            maxr = maxr - sub[i];
            sub[i] = 0;
            i++;
       }

       int cnt = 0;
       for(int i = 0;i<n;i++){
           if(sub[i]==0) cnt++;
       }
       
       if(maxr < 0) return cnt - 1;
       
       return cnt;

      

    }
};
