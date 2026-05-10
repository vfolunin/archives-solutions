class Solution {
public:
    vector<int> countWordOccurrences(vector<string> &parts, vector<string> &queries) {
        parts.back() += ' ';

        unordered_map<string, int> count;
        string word;
        for (string &part : parts) {
            for (char c : part) {
                if (c == ' ') {
                    if (!word.empty() && word.back() == '-')
                        word.pop_back();
                    count[word]++;
                    word = "";
                } else if (c == '-') {
                    if (word.empty())
                        continue;
                    if (word.back() == '-') {
                        word.pop_back();
                        count[word]++;
                        word = "";
                    } else {
                        word += c;
                    }
                } else {
                    word += c;
                }
            }
        }

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = count[queries[i]];
        return res;
    }
};