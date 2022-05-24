class Solution {
    template<typename T>
    auto get(T &a, int i) {
        return 0 <= i ? a[i] : 0;
    }
    
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        
        vector<int> lenTo(s.size());
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (get(s, i) == '(')
                continue;
            
            if (get(s, i - 1) == '(')
                lenTo[i] = get(lenTo, i - 2) + 2;
            else if (get(s, i - get(lenTo, i - 1) - 1) == '(')
                lenTo[i] = get(lenTo, i - get(lenTo, i - 1) - 2) + get(lenTo, i - 1) + 2;
            
            maxLen = max(maxLen, lenTo[i]);
        }
        
        return maxLen;
    }
};