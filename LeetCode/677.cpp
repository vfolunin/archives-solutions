struct Trie {
    struct Node {
        map<char, Node> next;
        int sum = 0;
    } root;

    void insert(const string &s, int val) {
        Node *n = &root;
        for (char c : s) {
            n->sum += val;
            n = &n->next[c];
        }
        n->sum += val;
    }
    
    int getSum(const string &s) {
        Node *n = &root;
        for (char c : s) {
            if (!n->next.count(c))
                return 0;
            n = &n->next[c];
        }
        return n->sum;
    }
};

class MapSum {
    unordered_map<string, int> pairs;
    Trie trie;
    
public:
    void insert(const string &s, int val) {
        if (pairs.count(s))
            trie.insert(s, -pairs[s]);
        trie.insert(s, val);
        pairs[s] = val;
    }
    
    int sum(const string &s) {
        return trie.getSum(s);
    }
};