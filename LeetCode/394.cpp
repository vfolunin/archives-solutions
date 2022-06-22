class Solution {
public:
    string decodeString(string s) {
        stringstream ss(s);
        vector<int> counts(1);
        vector<string> parts(1);
        
        while (ss.peek() != EOF) {
            if (isdigit(ss.peek())) {
                ss >> counts.emplace_back();
            } else {
                char c;
                ss >> c;
                
                if (c == '[') {
                    parts.emplace_back();
                } else if (c == ']') {
                    for (int i = 0; i < counts.back(); i++)
                        parts[parts.size() - 2] += parts.back();
                    counts.pop_back();
                    parts.pop_back();
                } else {
                    parts.back() += c;
                }
            }
        }
        
        return parts.back();
    }
};