class Solution {
public:
    int maximizeGreatness(vector<int> &a) {
        sort(a.begin(), a.end());

        int res = 0;

        for (int l = 0, r = 0; r < a.size(); l++) {
            while (r < a.size() && a[l] == a[r])
                r++;
    
            if (r < a.size()) {
                res++;
                r++;
            }
        }
        
        return res;
    }
};