#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // find center (src, src)
        // check if up, down, left, and right is the same
        // make them new color too, and also check their left, right, and top-bottom
        if(!image.size()) return image;
        int rows = image.size();
        int cols = image[0].size();
        int centerColor = image[sr][sc];
        dfs_flood_fill(image, sr, sc, newColor, centerColor);
        return image;
    }
    
    void dfs_flood_fill(vector<vector<int>>& image, int sr, int sc, int newColor, int centerColor){
        if(sc < 0 or sc >= image[0].size() or 
           sr < 0 or sr >= image.size() or image[sr][sc] == newColor or image[sr][sc] != centerColor) return; 
        
        image[sr][sc] = newColor;
        dfs_flood_fill(image, sr+1, sc, newColor, centerColor);
        dfs_flood_fill(image, sr-1, sc, newColor, centerColor);
        dfs_flood_fill(image, sr, sc+1, newColor, centerColor);
        dfs_flood_fill(image, sr, sc-1, newColor, centerColor);
    }
};
