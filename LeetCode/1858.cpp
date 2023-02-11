struct Trie {
    struct Node {
        map<char, Node> next;
        bool isWord = 0;
    } root;

    void insert(const string &s) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->isWord = 1;
    }

    void rec(Node *n, string &word, string &bestWord) {
        if (bestWord.size() < word.size())
            bestWord = word;
        
        for (auto &[c, to] : n->next) {
            if (to.isWord) {
                word.push_back(c);
                rec(&to, word, bestWord);
                word.pop_back();
            }
        }
    }
    
    string getBestWord() {
        string word, bestWord;
        rec(&root, word, bestWord);
        return bestWord;
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        Trie trie;
        for (string &word : words)
            trie.insert(word);
        return trie.getBestWord();
    }
};