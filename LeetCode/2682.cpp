class Solution {
public:
    vector<int> circularGameLosers(int size, int delta) {
        unordered_set<int> seen;
        for (int i = 1, pos = 0; !seen.count(pos); i++) {
            seen.insert(pos);
            pos = (pos + i * delta) % size;
        }
        
        vector<int> res;
        for (int pos = 0; pos < size; pos++)
            if (!seen.count(pos))
                res.push_back(pos + 1);
        return res;
    }
};