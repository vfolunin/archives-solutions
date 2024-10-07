struct Trie {
    struct Node {
        vector<Node *> next;
        Node() : next(26) {}
    } root;

    void insert(string &s) {
        Node *n = &root;
        for (char c : s) {
            if (!n->next[c - 'a'])
                n->next[c - 'a'] = new Node;
            n = n->next[c - 'a'];
        }
    }

    int getMaxPartSize(string &s, int from) {
        Node *n = &root;
        for (int i = from; i < s.size(); i++) {
            if (!n->next[s[i] - 'a'])
                return i - from;
            n = n->next[s[i] - 'a'];
        }
        return s.size() - from;
    }
};

class Solution {
public:
    int minValidStrings(vector<string> &a, string &s) {
        Trie trie;
        for (string &s : a)
            trie.insert(s);
        
        vector<int> res(s.size() + 1, 1e9);
        res[0] = 0;

        for (int size = 0; size < s.size(); size++) {
            if (res[size] == 1e9)
                continue;

            int maxPartSize = trie.getMaxPartSize(s, size);
            for (int partSize = 1; partSize <= maxPartSize; partSize++)
                res[size + partSize] = min(res[size + partSize], res[size] + 1);
        }
        
        return res.back() != 1e9 ? res.back() : -1;
    }
};