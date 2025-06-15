class Solution {
    vector<string> split(string &s) {
        stringstream ss(s);
        vector<string> res;
        for (string s; ss >> s; )
            res.push_back(s);
        return res;
    }

public:
    string generateTag(string &s) {
        vector<string> words = split(s);
        string res = "#";
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                res += i && !j ? toupper(words[i][j]) : tolower(words[i][j]);
        return res.substr(0, 100);
    }
};