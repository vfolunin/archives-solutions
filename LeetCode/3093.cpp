struct Trie {
    struct Node {
        map<char, Node> next;
        int minSize = 1e9, minIndex = 1e9;
    } root;

    void insert(string &s, int index) {
        Node *n = &root;
        for (char c : s) {
            if (n->minSize > s.size()) {
                n->minSize = s.size();
                n->minIndex = index;
            }
            n = &n->next[c];
        }
        if (n->minSize > s.size()) {
            n->minSize = s.size();
            n->minIndex = index;
        }
    }
    
    int get(string &s) {
        Node *n = &root;
        for (char c : s) {
            if (!n->next.count(c))
                return n->minIndex;
            n = &n->next[c];
        }
        return n->minIndex;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string> &words, vector<string> &queries) {
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            trie.insert(words[i], i);
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            reverse(queries[i].begin(), queries[i].end());
            res[i] = trie.get(queries[i]);
        }
        return res;
    }
};