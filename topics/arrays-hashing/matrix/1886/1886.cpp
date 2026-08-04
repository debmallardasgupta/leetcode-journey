class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            if(mat == target) return true;
            for (int j = 0; j < n; j++) {
                for (int k = j; k < m; k++) swap(mat[k][j], mat[j][k]);
            }
            reverse(mat.begin(), mat.end());
        }
        return false;
    }
};