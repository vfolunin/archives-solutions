class Solution {
    bool intersect(vector<int> &a, vector<int> &b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }
    
    vector<int> intersection(vector<int> &a, vector<int> &b) {
        return { max(a[0], b[0]), min(a[1], b[1]) };
    }
    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> res;
        
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ) {
            if (intersect(a[ai], b[bi]))
                res.push_back(intersection(a[ai], b[bi]));
            if (a[ai][1] < b[bi][1])
                ai++;
            else
                bi++;
        }
        
        return res;
    }
};