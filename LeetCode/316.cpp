class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> remaining(26);
        for (char c : s)
            remaining[c - 'a']++;
        
        vector<int> used(26);
        string stack;
        
        for (char c : s) {
            if (!used[c - 'a']) {
                while (!stack.empty() && stack.back() > c && remaining[stack.back() - 'a']) {
                    used[stack.back() - 'a'] = 0;
                    stack.pop_back();                
                }
                
                used[c - 'a'] = 1;
                stack.push_back(c);
            }
            
            remaining[c - 'a']--;
        }
        
        return stack;
    }
};