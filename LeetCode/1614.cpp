class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (char c : s) {
            if (c == '(')
                depth++;
            if (c == ')')
                depth--;
            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};