class Solution {
    bool endsWith(string &a, string &b) {
        if (a.size() < b.size())
            return 0;
        
        for (int i = 0; i < b.size(); i++)
            if (a[a.size() - b.size() + i] != b[i])
                return 0;
        
        return 1;
    }
    
public:
    string removeOccurrences(string s, string part) {
        string stack;
        
        for (char c : s) {
            stack.push_back(c);
            if (endsWith(stack, part))
                for (int i = 0; i < part.size(); i++)
                    stack.pop_back();
        }
        
        return stack;
    }
};