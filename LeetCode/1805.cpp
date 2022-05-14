class Solution {
    string trimLeadingZeros(string &s) {
        reverse(s.begin(), s.end());
        while (s.size() > 1 && s.back() == '0')
            s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
    
public:
    int numDifferentIntegers(string s) {
        unordered_set<string> values;
        string value;
        
        for (char c : s) {
            if (isdigit(c)) {
                value += c;
            } else if (!value.empty()) {
                values.insert(trimLeadingZeros(value));
                value = "";
            }
        }
        if (!value.empty())
            values.insert(trimLeadingZeros(value));
        
        return values.size();
    }
};