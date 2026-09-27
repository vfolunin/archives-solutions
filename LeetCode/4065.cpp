class Solution {
public:
    vector<int> rearrangeArray(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> res;
        while (res.size() < a.size()) {
            for (auto &[value, count] : count) {
                if (count) {
                    res.push_back(value);
                    count--;
                }
            }
        }
        return res;
    }
};