class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int res = 0;
        
        for (int ai = 0, bi = 0; ai < a.size(); ai++) {
            while (bi < b.size() && a[ai] > b[bi])
                bi++;
            
            if (bi < b.size()) {
                res++;
                bi++;
            }
        }
        
        return res;
    }
};