class Solution {
    vector<int> getRank(vector<int> &prefs) {
        vector<int> res(prefs.size() + 1, prefs.size());
        for (int i = 0; i < prefs.size(); i++)
            res[prefs[i]] = i;
        return res;
    }
    
    int prefers(vector<int> &prefs, int a, int b) {
        return prefs[a] < prefs[b];
    }
    
public:
    int unhappyFriends(int n, vector<vector<int>> &prefs, vector<vector<int>> &pairs) {
        for (vector<int> &prefs : prefs)
            prefs = getRank(prefs);
        
        int res = 0;

        for (vector<int> &ab : pairs) {
            int a = ab[0], b = ab[1];
            
            for (vector<int> &cd : pairs) {
                int c = cd[0], d = cd[1];
                if (prefers(prefs[a], c, b) && prefers(prefs[c], a, d) ||
                    prefers(prefs[a], d, b) && prefers(prefs[d], a, c)) {
                    res++;
                    break;
                }
            }
            
            for (vector<int> &cd : pairs) {
                int c = cd[0], d = cd[1];
                if (prefers(prefs[b], c, a) && prefers(prefs[c], b, d) ||
                    prefers(prefs[b], d, a) && prefers(prefs[d], b, c)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};