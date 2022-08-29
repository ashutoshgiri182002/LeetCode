class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        
        map<int, priority_queue<int, vector<int>, greater<int>>> diagonal;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diagonal[i - j].push(mat[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = diagonal[i - j].top();
                diagonal[i - j].pop();
            }
        }
        
        return mat;
    }
};
