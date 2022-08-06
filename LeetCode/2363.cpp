class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &a, vector<vector<int>> &b) {
        map<int, int> resMap;
        
        for (vector<int> &item : a)
            resMap[item[0]] += item[1];
        
        for (vector<int> &item : b)
            resMap[item[0]] += item[1];
        
        vector<vector<int>> res;
        for (auto &[value, weight] : resMap)
            res.push_back({ value, weight });
        return res;
    }
};