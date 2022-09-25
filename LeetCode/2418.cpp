class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        vector<pair<int, string>> pairs(names.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { heights[i], names[i] };
        sort(pairs.rbegin(), pairs.rend());
        
        vector<string> res(pairs.size());
        for (int i = 0; i < pairs.size(); i++)
            res[i] = pairs[i].second;
        return res;
    }
};