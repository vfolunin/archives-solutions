class MagicDictionary {
    vector<string> dict;
    
    bool distIsOne(const string &a, const string &b) {
        if (a.size() != b.size())
            return 0;
        
        int dist = 0;
        for (int i = 0; i < a.size() && dist <= 1; i++)
            dist += a[i] != b[i];
        return dist == 1;
    }
    
public:
    void buildDict(const vector<string> &dictionary) {
        dict = dictionary;
    }
    
    bool search(const string &word) {
        for (string &dictWord : dict)
            if (distIsOne(dictWord, word))
                return 1;
        return 0;
    }
};