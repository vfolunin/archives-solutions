class Solution {
public:
    string decodeMessage(string key, string message) {
        string code(26, ' ');
        unordered_set<char> processed;
        for (char c : key) {
            if (c != ' ' && !processed.count(c)) {
                code[c - 'a'] = processed.size() + 'a';
                processed.insert(c);
            }
        }
        
        for (char &c : message)
            c = c == ' ' ? c : code[c - 'a'];
        return message;
    }
};