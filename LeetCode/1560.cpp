class Solution {
public:
    vector<int> mostVisited(int n, vector<int> &rounds) {
        vector<int> count(n, 3);
        for (int i = 0; i < rounds[0] - 1; i++)
            count[i]--;
        for (int i = rounds.back(); i < n; i++)
            count[i]--;
        
        int maxCount = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (maxCount < count[i]) {
                maxCount = count[i];
                res = { i + 1 };
            } else if (maxCount == count[i]) {
                res.push_back(i + 1);
            }
        }
        
        return res;
    }
};