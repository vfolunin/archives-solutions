class Solution {
public:
    string robotWithString(string &s) {
        multiset<char> chars = { s.begin(), s.end() };
        string stack, res;
        
        for (char c : s) {
            stack.push_back(c);
            chars.erase(chars.find(c));
            
            while (!stack.empty() && !chars.empty() && stack.back() <= *chars.begin()) {
                res.push_back(stack.back());
                stack.pop_back();
            }
        }
        
        res.insert(res.end(), stack.rbegin(), stack.rend());
        
        return res;
    }
};