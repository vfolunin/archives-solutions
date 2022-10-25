class Solution {
public:
    int maxEqualFreq(vector<int> &a) {
        unordered_map<int, int> count;
        multiset<int> counts;
        
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (auto it = counts.find(count[a[i]]); it != counts.end())
                counts.erase(it);
            count[a[i]]++;
            counts.insert(count[a[i]]);
            
            if (counts.size() == 1 || *counts.begin() == 1 && *next(counts.begin()) == *prev(counts.end()) ||
                *counts.begin() == *prev(prev(counts.end())) && *prev(prev(counts.end())) + 1 == *prev(counts.end()))
                res = i + 1;
        }
        
        return res;
    }
};