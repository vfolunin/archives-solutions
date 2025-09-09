class Solution {
public:
    long long countSubmatrices(vector<vector<int>> &a, int limit) {
        vector<vector<int>> lCount(a.size(), vector<int>(a[0].size()));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] <= limit)
                    lCount[y][x] = x && a[y][x - 1] >= a[y][x] ? lCount[y][x - 1] + 1 : 1;
        
        long long res = 0;

        for (int x = 0; x < a[0].size(); x++) {
            vector<int> up(a.size(), -1), stack;
            for (int y = a.size() - 1; y >= 0; y--) {
                while (!stack.empty() && lCount[stack.back()][x] > lCount[y][x]) {
                    up[stack.back()] = y;
                    stack.pop_back();
                }
                stack.push_back(y);
            }

            vector<int> down(a.size(), a.size());
            stack.clear();
            for (int y = 0; y < a.size(); y++) {
                while (!stack.empty() && lCount[stack.back()][x] >= lCount[y][x]) {
                    down[stack.back()] = y;
                    stack.pop_back();
                }
                stack.push_back(y);
            }

            for (int y = 0; y < a.size(); y++)
                res += 1LL * lCount[y][x] * (down[y] - y) * (y - up[y]);
        }

        return res;
    }
};