class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int index = 1;
        for (char c : sentence) {
            if (c != ' ') {
                word += c;
                if (word == searchWord)
                    return index;
            } else {
                word.clear();
                index++;
            }
        }
        return -1;
    }
};