class Solution {
public:
    string largestMerge(string &a, string &b) {
        string res;        
        for (int ai = 0, bi = 0; ai < a.size() || bi < b.size(); ) {
            if (bi == b.size() || ai < a.size() && (a[ai] > b[bi] || a[ai] == b[bi] && a.substr(ai) > b.substr(bi)))
                res += a[ai++];
            else
                res += b[bi++];
        }        
        return res;
    }
};