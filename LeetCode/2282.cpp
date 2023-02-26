class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> res(h, vector<int>(w));

        for (int y = 0; y < h; y++) {
            vector<int> stack;
            for (int x = 0; x < w; x++) {
                int next = 0;
                while (!stack.empty() && a[y][stack.back()] < a[y][x]) {
                    res[y][stack.back()] += a[y][stack.back()] > next;
                    next = a[y][stack.back()];
                    stack.pop_back();
                }
                if (!stack.empty())
                    res[y][stack.back()]++;
                stack.push_back(x);
            }
        }

        for (int x = 0; x < w; x++) {
            vector<int> stack;
            for (int y = 0; y < h; y++) {
                int next = 0;
                while (!stack.empty() && a[stack.back()][x] < a[y][x]) {
                    res[stack.back()][x] += a[stack.back()][x] > next;
                    next = a[stack.back()][x];
                    stack.pop_back();
                }
                if (!stack.empty())
                    res[stack.back()][x]++;
                stack.push_back(y);
            }
        }

        return res;
    }
};