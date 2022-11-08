class Solution {
public:
    string smallestSubsequence(string &s, int len, char c, int cCount) {
        int lcCount = 0, rcCount = count(s.begin(), s.end(), c);
        
        string stack;
        for (int i = 0; i < s.size(); i++) {
            while (!stack.empty() && stack.back() > s[i]) {
                int nlLen = stack.size() - 1;
                int nrLen = s.size() - i;
                if (nlLen + nrLen < len)
                    break;
                
                int nlcCount = lcCount - (stack.back() == c);
                int nrcCount = rcCount;
                if (nlcCount + nrcCount < cCount)
                    break;
                
                stack.pop_back();
                lcCount = nlcCount;
            }
            
            if (stack.size() < len && (s[i] == c || len - (int)stack.size() > cCount - lcCount)) {
                stack.push_back(s[i]);
                lcCount += s[i] == c;
            }
            
            rcCount -= s[i] == c;
        }
        
        return stack;
    }
};