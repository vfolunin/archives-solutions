class Solution {
public:
    bool canFormArray(vector<int> &a, vector<vector<int>> &pieces) {
        unordered_set<int> seen;
        unordered_map<int, int> next;
        
        for (vector<int> &piece : pieces) {
            for (int i = 0; i + 1 < piece.size(); i++) {
                seen.insert(piece[i]);
                next[piece[i]] = piece[i + 1];
            }
            seen.insert(piece.back());
        }
        
        for (int i = 0; i + 1 < a.size(); i++)
            if (!seen.count(a[i]) || next.count(a[i]) && next[a[i]] != a[i + 1])
                return 0;
        
        return seen.count(a.back()) && !next.count(a.back());
    }
};