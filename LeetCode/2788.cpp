class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string> &a, char separator) {
        vector<string> words;

        for (string &s : a) {
            string word;

            for (char c : s) {
                if (c != separator) {
                    word += c;
                } else if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }

            if (!word.empty())
                words.push_back(word);
        }

        return words;
    }
};