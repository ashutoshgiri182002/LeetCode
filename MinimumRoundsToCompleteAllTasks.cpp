class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int n = tasks.size();
        unordered_map<int,int>mp;

        for(int i = 0;i<n;i++){
            mp[tasks[i]]++;
        }

         int cnt = 0;
        
        for(auto x:mp){
            if(x.second==1) return -1;
            else{
                int q = x.second/3;
                int r = x.second%3;
                if(r==0) cnt +=q;
                else
                cnt +=q+1;
            }
        }
          
          return cnt;
    }
};
