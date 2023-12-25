class Solution {
public:
    vector<int> numberGame(vector<int> &a) {
        multiset<int> values(a.begin(), a.end());
        vector<int> res;

        while (!values.empty()) {
            int value1 = *values.begin();
            values.erase(values.begin());
            int value2 = *values.begin();
            values.erase(values.begin());
            
            res.push_back(value2);
            res.push_back(value1);
        }

        return res;
    }
};