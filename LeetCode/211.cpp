class WordDictionary {
    struct Node {
        map<char, Node> next;
        bool isTerminal = 0;
    } root;
    
    bool contains(Node *n, const string &s, int i) {
        if (i == s.size())
            return n->isTerminal;
        
        if (s[i] != '.') {
            if (n->next.count(s[i]))
                return contains(&n->next[s[i]], s, i + 1);
            else
                return 0;
        }
        
        for (auto &[c, to] : n->next)
            if (contains(&to, s, i + 1))
                return 1;
        return 0;
    }

public:    
    void addWord(const string &s) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->isTerminal = 1;
    }
    
    bool search(const string &s) {
        return contains(&root, s, 0);
    }
};