class Codec {
    void encode(string &s, stringstream &ss) {
        for (int i = 0; i < s.size(); ) {
            int count = min<int>(255, s.size() - i);
            ss << (char)count;
            for (int j = 0; j < count; i++, j++)
                ss << s[i];
        }
        ss << '\0';
    }

    string decode(stringstream &ss) {
        string s;
        while (1) {
            int count = ss.get();
            if (!count)
                return s;
            for (int i = 0; i < count; i++)
                s += ss.get();
        }
    }

public:
    string encode(vector<string> &a) {
        stringstream ss;
        for (string &s : a)
            encode(s, ss);
        return ss.str();
    }

    vector<string> decode(const string &s) {
        vector<string> a;
        for (stringstream ss(s); ss.peek() != EOF; ) 
            a.push_back(decode(ss));
        return a;
    }
};