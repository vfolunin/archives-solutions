class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<int> res(a.size());
        int pos = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (i) {
                do
                    pos = (pos + 1) % a.size();
                while (res[pos]);
            }
            
            res[pos] = a[i];
            
            if (i + 1 < a.size()) {
                do
                    pos = (pos + 1) % a.size();
                while (res[pos]);
            }
        }
        
        return res;
    }
};