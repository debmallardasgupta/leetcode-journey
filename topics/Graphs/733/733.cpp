class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int start) {
        
        if(sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != start) return;

        image[sr][sc] = color;
        dfs(image,sr - 1,sc,color,m,n,start);
        dfs(image,sr + 1,sc,color,m,n,start);
        dfs(image,sr,sc - 1,color,m,n,start);
        dfs(image,sr,sc + 1,color,m,n,start);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc];
        if(start == color) return image;
        dfs(image,sr,sc,color,m,n,start);
        return image;
    }
};