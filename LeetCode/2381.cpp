class Solution {
public:
    string shiftingLetters(string &s, vector<vector<int>> &shifts) {       
        vector<int> delta(s.size());
        for (vector<int> &shift : shifts) {
            delta[shift[0]] += shift[2] ? 1 : -1;
            if (shift[1] + 1 < s.size())
                delta[shift[1] + 1] += shift[2] ? -1 : 1;
        }
        
        int curDelta = 0;
        for (int i = 0; i < s.size(); i++) {
            curDelta += delta[i];
            s[i] -= 'a';
            s[i] = ((s[i] + curDelta) % 26 + 26) % 26;
            s[i] += 'a';
        }
        
        return s;
    }
};