class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        
        vector<vector<int>> res;
        for (vector<int> &value : people)
            res.insert(res.begin() + value[1], value);
        
        return res;
    }
};