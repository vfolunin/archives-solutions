class Trie {
    struct Vertex {
        map<char, Vertex> next;
        int size = 0;
    } root;

public:
    void insert(const string &s) {
        Vertex *v = &root;
        for (const char c : s)
            v = &v->next[c];
        v->size++;
    }
    
    bool search(const string &s) {
        Vertex *v = &root;
        for (const char c : s) {
            if (!v->next.count(c))
                return 0;
            v = &v->next[c];
        }
        return v->size;
    }
    
    bool startsWith(const string &s) {
        Vertex *v = &root;
        for (const char c : s) {
            if (!v->next.count(c))
                return 0;
            v = &v->next[c];
        }
        return 1;
    }
};