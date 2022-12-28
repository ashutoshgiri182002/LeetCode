class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int>pq;

        for(int i =0;i<n;i++){
            pq.push(piles[i]);
        }

        while(k){
           float x = pq.top();
           pq.pop();
           x = x/2;
           pq.push(ceil(x));
            k--;
        }
        
        int sum = 0;
       while(!pq.empty()){
           sum +=pq.top();
           pq.pop();
       }
      
      return sum;
    }
};
