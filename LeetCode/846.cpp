class Solution {
public:
    bool isNStraightHand(vector<int> &a, int groupSize) {
        if (a.size() % groupSize)
            return 0;
        
        multiset<int> values(a.begin(), a.end());
        while (!values.empty()) {
            int from = *values.begin();
            values.erase(values.begin());
            
            for (int i = 1; i < groupSize; i++) {
                if (auto it = values.find(from + i); it != values.end())
                    values.erase(it);
                else
                    return 0;
            }
        }
        
        return 1;
    }
};