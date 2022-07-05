class Solution {
public:
    bool isPossibleDivide(vector<int> &a, int k) {
        if (a.size() % k)
            return 0;
        
        multiset<int> values(a.begin(), a.end());
        while (!values.empty()) {
            int from = *values.begin();
            for (int i = 0; i < k; i++) {
                if (auto it = values.find(from + i); it != values.end())
                    values.erase(it);
                else
                    return 0;
            }
        }
        
        return 1;
    }
};