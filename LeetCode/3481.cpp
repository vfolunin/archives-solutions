class Solution {
public:
    string applySubstitutions(vector<vector<string>> &replacements, string &text) {
        unordered_map<string, string> replaceMap;
        for (vector<string> &replacement : replacements)
            replaceMap[replacement[0]] = replacement[1];

        while (text.find('%') != -1) {
            string nextText;
            for (int i = 0; i < text.size(); ) {
                if (text[i] == '%') {
                    int j = text.find('%', i + 1);
                    nextText += replaceMap[text.substr(i + 1, j - i - 1)];
                    i = j + 1;
                } else {
                    nextText += text[i];
                    i++;
                }
            }
            text.swap(nextText);
        }
        return text;
    }
};