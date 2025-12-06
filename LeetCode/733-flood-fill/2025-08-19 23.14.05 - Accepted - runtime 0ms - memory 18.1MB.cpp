class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& newImage, int val,
             int color) {
        if (sr < 0 || sr >= newImage.size() || sc < 0 ||
            sc >= newImage[0].size())
            return;
        if (newImage[sr][sc] != val || newImage[sr][sc] == color)
            return;
        newImage[sr][sc] = color;
        dfs(sr - 1, sc, newImage, val, color);
        dfs(sr + 1, sc, newImage, val, color);
        dfs(sr, sc - 1, newImage, val, color);
        dfs(sr, sc + 1, newImage, val, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int val = image[sr][sc];
        vector<vector<int>>& newImage = image;
        dfs(sr, sc, newImage, val, color);
        return newImage;
    }
};