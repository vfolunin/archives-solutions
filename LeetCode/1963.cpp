class Solution {
public:
    int minSwaps(string s) {
        int depth = 0;
        for (char c : s) {
            if (c == '[')
                depth++;
            else
                depth = max(depth - 1, 0);
        }
        
        return (depth + 1) / 2;
    }
};