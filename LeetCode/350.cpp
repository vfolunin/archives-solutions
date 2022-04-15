class Solution {
public:
    vector<int> intersect(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int> res;
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ) {
            if (a[ai] < b[bi]) {
                ai++;
            } else if (a[ai] > b[bi]) {
                bi++;
            } else {
                res.push_back(a[ai]);
                ai++;
                bi++;
            }
        }
        
        return res;
    }
};