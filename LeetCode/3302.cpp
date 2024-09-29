class Solution {
public:
    vector<int> validSequence(string &text, string &word) {
        vector<int> suffixSize(text.size());
        suffixSize.back() = text.back() == word.back();
        for (int i = (int)suffixSize.size() - 2; i >= 0; i--) {
            if (suffixSize[i + 1] == word.size())
                suffixSize[i] = word.size();
            else
                suffixSize[i] = suffixSize[i + 1] + (text[i] == word[word.size() - suffixSize[i + 1] - 1]);
        }

        vector<int> res;
        bool changed = 0;
        for (int i = 0; i < text.size() && res.size() < word.size(); i++) {
            if (text[i] == word[res.size()]) {
                res.push_back(i);
            } else if (!changed && (res.size() + 1 == word.size() || i + 1 < text.size() && res.size() + 1 + suffixSize[i + 1] >= word.size())) {
                res.push_back(i);
                changed = 1;
            }
        }
        return res.size() == word.size() ? res : vector<int>();
    }
};