class Solution {
    void rec(vector<int> &a, int i, int partCount, vector<vector<int>> &parts, int &res) {
        if (i == a.size()) {
            int sum = 0;
            for (vector<int> &part : parts)
                sum += part.back() - part.front();
            res = min(res, sum);
            return;
        }
        
        for (int pi = 0; pi < partCount; pi++) {
            if (parts[pi].size() == a.size() / partCount ||
                !parts[pi].empty() && parts[pi].back() == a[i] ||
                pi && parts[pi - 1] == parts[pi])
                continue;
            
            parts[pi].push_back(a[i]);
            rec(a, i + 1, partCount, parts, res);
            parts[pi].pop_back();
        }
    }
    
public:
    int minimumIncompatibility(vector<int> &a, int partCount) {
        if (a.size() == partCount)
            return 0;
        
        sort(a.begin(), a.end());
        
        vector<vector<int>> parts(partCount);
        int res = 1e9;
        rec(a, 0, partCount, parts, res);
        
        return res != 1e9 ? res : -1;
    }
};