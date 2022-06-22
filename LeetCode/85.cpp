class Solution {
public:
    int maximalRectangle(vector<vector<char>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        vector<int> hist(w);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == '0') 
                    hist[x] = 0;
                else
                    hist[x]++;
            }
            
            vector<int> stack;
            vector<int> l(w, -1);
            for (int x = w - 1; x >= 0; x--) {
                while (!stack.empty() && hist[stack.back()] > hist[x]) {
                    l[stack.back()] = x;
                    stack.pop_back();
                }
                stack.push_back(x);
            }
            
            stack.clear();
            vector<int> r(w, w);
            for (int x = 0; x < w; x++) {
                while (!stack.empty() && hist[stack.back()] > hist[x]) {
                    r[stack.back()] = x;
                    stack.pop_back();
                }
                stack.push_back(x);
            }
            
            for (int x = 0; x < w; x++)
                res = max(res, hist[x] * (r[x] - l[x] - 1));
        }
        
        return res;
    }
};