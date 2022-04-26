class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        return is_sorted(words.begin(), words.end(), [&](auto &a, auto &b) {
            for (int i = 0; i < a.size() && i < b.size(); i++) {
                int ap = order.find(a[i]), bp = order.find(b[i]);
                if (ap != bp)
                    return ap < bp;
            }
            return a.size() < b.size();                
        });
    }
};