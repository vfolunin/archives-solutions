class Solution {
    string maskEmail(string &s) {
        transform(s.begin(), s.end(), s.begin(), [](char c) {
            return tolower(c);
        });
        
        stringstream ss;
        ss << s[0] << "*****" << s.substr(s.find('@') - 1);
        return ss.str();
    }
    
    string maskPhone(string &s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isdigit(c);
        }), s.end());
        
        stringstream ss;
        if (s.size() > 10)
            ss << "+" << string(s.size() - 10, '*') << "-";
        ss << "***-***-" << s.substr(s.size() - 4);
        return ss.str();
    }
    
public:
    string maskPII(string &s) {
        return s.find('@') != -1 ? maskEmail(s) : maskPhone(s);
    }
};