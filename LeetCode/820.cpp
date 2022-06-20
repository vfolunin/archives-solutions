class Trie {
    struct Node {
        map<char, Node> next;
    } root;
    
    int dfs(Node *n, int size) {
        if (n->next.empty())
            return size;
        
        int res = 0;
        for (auto &[_, to] : n->next)
            res += dfs(&to, size + 1);
        return res;
    }

public:
    void insert(const string &s) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
    }
    
    int size() {
        return dfs(&root, 1);
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        Trie trie;
        for (string &word : words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
        return trie.size();
    }
};