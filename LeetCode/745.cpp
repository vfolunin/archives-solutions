class Trie {
    struct Node {
        map<char, Node> next;
        int maxVal = 0;
    } root;
    
    int insert(Node *n, const string &s, int i, int val) {
        if (i == s.size())
            return n->maxVal = max(n->maxVal, val);
        return n->maxVal = max(n->maxVal, insert(&n->next[s[i]], s, i + 1, val));
    }

public:
    void insert(const string &s, int val) {
        insert(&root, s, 0, val);
    }
    
    int getMaxVal(const string &s) {
        Node *n = &root;
        for (char c : s) {
            if (!n->next.count(c))
                return -1;
            n = &n->next[c];
        }
        return n->maxVal;
    }
};

class WordFilter {
    Trie trie;
    
public:
    WordFilter(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            for (int suffixSize = 0; suffixSize <= words[i].size(); suffixSize++)
                trie.insert(words[i].substr(words[i].size() - suffixSize) + "#" + words[i], i);
        }
    }
    
    int f(const string &prefix, const string &suffix) {
        return trie.getMaxVal(suffix + "#" + prefix);
    }
};