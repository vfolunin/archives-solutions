class Solution {
public:
    bool checkZeroOnes(string s) {
        int curRow = 1;
        vector<int> maxRow(2);
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                curRow++;
            } else {
                maxRow[s[i - 1] - '0'] = max(maxRow[s[i - 1] - '0'], curRow);
                curRow = 1;
            }
        }
        maxRow[s.back() - '0'] = max(maxRow[s.back() - '0'], curRow);
        
        return maxRow[0] < maxRow[1];
    }
};