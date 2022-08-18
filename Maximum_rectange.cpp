class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>left;
        vector<int>right;
        stack<pair<int,int>>st;
        stack<pair<int,int>>st1;
        
        //Get the nearest smaller element to the left
        
        for(int i = 0;i<heights.size();i++){
            while(st.size()>0 and st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.size()==0){
                left.push_back(-1);
            }
            
            else{
                left.push_back(st.top().second);
            }
            
            st.push({heights[i],i});
        }
        
        //Get the nearest smaller element to right
        
         for(int i = heights.size()-1;i>=0;i--){
            while(st1.size()>0 and st1.top().first >= heights[i]){
                st1.pop();
            }
            
            if(st1.size()==0){
                right.push_back(heights.size());
            }
            
            else{
                right.push_back(st1.top().second);
            }
              st1.push({heights[i],i});
        }
        
        reverse(right.begin(),right.end());
             
        vector<int>area;
        for(int i = 0;i<heights.size();i++){
            area.push_back((right[i] - left[i]-1)*heights[i]);
        }
        
        return *max_element(area.begin(),area.end());
            
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int>v;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int j = 0;j<m;j++){
            v.push_back(matrix[0][j]-'0');
        }
        
        int maxi = largestRectangleArea(v);
        cout<<maxi<<endl;
        
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                
                if(matrix[i][j]=='0'){
                
                    v[j] = 0;
                }
                
                else{
                    v[j] = v[j] + matrix[i][j] - '0';
                }
            }
            
            
            
            int temp = largestRectangleArea(v);
            
            maxi = max(temp,maxi);
        }
        
        return maxi;
        
    }
};
