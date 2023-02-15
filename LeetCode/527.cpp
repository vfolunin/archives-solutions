struct Abbreviation {
    int index;
    string word;
    int prefixSize = 1;

    bool operator == (const Abbreviation &that) const {
        return index == that.index && prefixSize == that.prefixSize;
    }

    string get() {
        string res = word.substr(0, prefixSize) + to_string(word.size() - prefixSize - 1) + word.back();
        if (res.size() < word.size())
            return res;
        else
            return word;
    }
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string> &words) {
        unordered_map<string, vector<Abbreviation>> abbreviations;
        for (int i = 0; i < words.size(); i++) {
            Abbreviation abbr = { i, words[i] };
            abbreviations[abbr.get()].push_back(abbr);
        }

        while (1) {
            unordered_map<string, vector<Abbreviation>> nextAbbreviations;

            for (auto &[s, abbrs] : abbreviations) {
                if (abbrs.size() == 1) {
                    nextAbbreviations[s] = abbrs;
                } else {
                    for (Abbreviation &abbr : abbrs) {
                        abbr.prefixSize++;
                        nextAbbreviations[abbr.get()].push_back(abbr);
                    }
                }
            }

            if (abbreviations != nextAbbreviations)
                abbreviations.swap(nextAbbreviations);
            else
                break;
        }

        vector<string> res(words.size());
        for (auto &[s, abbrs] : abbreviations)
            res[abbrs[0].index] = abbrs[0].get();
        return res;
    }
};