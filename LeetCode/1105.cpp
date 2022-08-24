class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int width) {
        vector<int> height(books.size() + 1, 1e9);
        height[0] = 0;
        
        for (int i = 1; i <= books.size(); i++) {
            int curWidth = 0, curHeight = 0;
            
            for (int j = 1; j <= i; j++) {
                curWidth += books[i - j][0];
                curHeight = max(curHeight, books[i - j][1]);
                
                if (curWidth > width)
                    break;
                
                height[i] = min(height[i], height[i - j] + curHeight);
            }
        }
        
        return height.back();
    }
};