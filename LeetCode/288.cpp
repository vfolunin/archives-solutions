string getAbbr(const string &s) {
    if (s.size() <= 2)
        return s;
    return s.front() + to_string(s.size() - 2) + s.back();
}

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> abbr;

public:
    ValidWordAbbr(vector<string> &words) {
        for (string &word : words)
            abbr[getAbbr(word)].insert(word);
    }
    
    bool isUnique(const string &word) {
        auto it = abbr.find(getAbbr(word));
        return it == abbr.end() || it->second.size() == 1 && *it->second.begin() == word;
    }
};