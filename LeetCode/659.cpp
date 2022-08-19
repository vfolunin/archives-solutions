class Solution {
public:
    bool isPossible(vector<int> &a) {
        unordered_map<int, multiset<int>> seqs;
        
        for (int value : a) {
            int size = 0;
            
            if (seqs.count(value - 1)) {
                size = *seqs[value - 1].begin();
                
                seqs[value - 1].erase(seqs[value - 1].begin());
                if (seqs[value - 1].empty())
                    seqs.erase(value - 1);
            }
            
            seqs[value].insert(size + 1);
        }
        
        for (auto [value, sizes] : seqs)
            if (*sizes.begin() < 3)
                return 0;
        return 1;
    }
};