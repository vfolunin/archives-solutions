class Solution {
    vector<string> split(string &line, const string &separators) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (separators.find(c) == -1) {
                word += c;
            } else {
                words.push_back(word);
                word.clear();
            }
        }
        words.push_back(word);
        return words;
    }
    
    bool isDigit(string &s) {
        for (char c : s)
            if (!isdigit(c))
                return 0;
        return 1;
    }
    
    bool isIpV4(string &s) {
        vector<string> tokens = split(s, ".");
        if (tokens.size() != 4)
            return 0;
        
        for (string &token : tokens)
            if (token.empty() || token.size() > 3 || token[0] == '0' && token.size() > 1 ||
                !isDigit(token) || stoi(token) > 255)
                return 0;
        
        return 1;
    }
    
    bool isHex(string &s) {
        for (char c : s)
            if (!isxdigit(c))
                return 0;
        return 1;
    }
    
    bool isIpV6(string &s) {
        vector<string> tokens = split(s, ":");
        if (tokens.size() != 8)
            return 0;
        
        for (string &token : tokens)
            if (token.empty() || token.size() > 4 || !isHex(token))
                return 0;
        
        return 1;
    }
    
public:
    string validIPAddress(string &s) {
        if (isIpV4(s))
            return "IPv4";
        else if (isIpV6(s))
            return "IPv6";
        else
            return "Neither";
    }
};