class Trie {
    struct Node {
        map<char, Node> next;
        int startingCount = 0, equalCount = 0;
    } root;

public:    
    void insert(const string &s) {
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            n->startingCount++;
        }
        n->equalCount++;
    }
    
    int countWordsEqualTo(const string &s) {
        Node *n = &root;
        for (char c : s) {
            if (n->next.count(c))
                n = &n->next[c];
            else
                return 0;
        }
        return n->equalCount;
    }
    
    int countWordsStartingWith(const string &s) {
        Node *n = &root;
        for (char c : s) {
            if (n->next.count(c))
                n = &n->next[c];
            else
                return 0;
        }
        return n->startingCount;        
    }
    
    void erase(const string &s) {
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            n->startingCount--;
        }
        n->equalCount--;
    }
};