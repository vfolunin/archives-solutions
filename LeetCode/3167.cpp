class Solution {
public:
    string betterCompression(string &s) {
        vector<int> count(26);
        
        stringstream ss(s);
        char c;
        int delta;
        while (ss >> c >> delta)
            count[c - 'a'] += delta;
        
        ss = stringstream();
        for (int i = 0; i < count.size(); i++)
            if (count[i])
                ss << (char)(i + 'a') << count[i];
        return ss.str();
    }
};