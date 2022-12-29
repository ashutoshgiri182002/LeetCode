class Solution {
public:
    struct comp {
        bool operator()(pair<long long int,long long int>& p1, pair<long long int,long long int>& p2) {
            if(p1.second == p2.second) return p1.first > p2.first;
            return p1.second > p2.second;
        }  
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> complete(tasks.size(), 0);
        
        map<long long int, vector<long long int>> intime;
        
        for(long long int i = 0 ; i < tasks.size() ; i++) {
            intime[tasks[i][0]].push_back(i);
        }
        
        
        
        priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, comp> haha;
     
        
        vector<int> answer;
        
        long long int currTime = intime.begin()->first;
        
        while(intime.size() || haha.size()) {
            
            if(haha.size()) {
                answer.push_back(haha.top().first);
                currTime += haha.top().second;
                haha.pop();
            }
            
            while(intime.size() && intime.begin()->first <= currTime) {
                for(auto i : intime.begin()->second) {
                    haha.push(make_pair(i, tasks[i][1]));
                }
                
                intime.erase(intime.begin());
            }
            
            if(!haha.size() && intime.size()) {
                currTime = intime.begin()->first;
            }
            
        }
        
        return answer;
        
        
    }
};
