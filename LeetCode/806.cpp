class Solution {
public:
    vector<int> numberOfLines(vector<int> &width, string s) {
        int lineCount = 1, lineWidth = 0;
        for (char c : s) {
            if (lineWidth + width[c - 'a'] <= 100) {
                lineWidth += width[c - 'a'];
            } else {
                lineCount++;
                lineWidth = width[c - 'a'];
            }
        }
        return { lineCount, lineWidth };
    }
};