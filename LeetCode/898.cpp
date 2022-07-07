class Solution {
public:
    int subarrayBitwiseORs(vector<int> &a) {
        vector<unordered_set<int>> values(3);

        for (int value : a) {
            values[1] = { value };
            for (int prevValue : values[0])
                values[1].insert(prevValue | value);
            
            for (int prevValue : values[1])
                values[2].insert(prevValue);
            
            values[0].swap(values[1]);
        }
        
        return values[2].size();
    }
};