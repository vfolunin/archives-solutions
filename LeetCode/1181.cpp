class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }

    string join(vector<string> &words) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }

    string combine(vector<string> &a, vector<string> &b) {
        vector<string> words = a;
        words.insert(words.end(), next(b.begin()), b.end());
        return join(words);
    }

public:
    vector<string> beforeAndAfterPuzzles(vector<string> &phrases) {
        vector<vector<string>> words(phrases.size());
        for (int i = 0; i < phrases.size(); i++) 
            words[i] = split(phrases[i]);

        unordered_map<string, vector<int>> from;
        for (int i = 0; i < words.size(); i++)
            from[words[i][0]].push_back(i);

        set<string> res;
        for (int i = 0; i < words.size(); i++)
            for (int j : from[words[i].back()])
                if (i != j)
                    res.insert(combine(words[i], words[j]));
        return { res.begin(), res.end() };
    }
};