class Trie {
    struct Vertex {
        bool isTerminal = false;
        unordered_map<char, Vertex> next;
        Vertex *sufLink = nullptr;
        vector<Vertex *> autLink;
    } root, *state;

public:
    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s)
            v = &v->next[c];
        v->isTerminal = true;
    }

    void build(int alphabetSize) {
        queue<Vertex *> q;
        root.sufLink = &root;
        q.push(&root);

        while (!q.empty()) {
            Vertex *v = q.front();
            q.pop();

            for (auto &[c, to] : v->next) {
                to.sufLink = (v == &root ? &root : v->sufLink->autLink[c - 'a']);                
                q.push(&to);
            }

            v->autLink.resize(alphabetSize);
            for (char c = 'a'; c < 'a' + alphabetSize; c++) {
                if (v->next.count(c))
                    v->autLink[c - 'a'] = &v->next[c];
                else
                    v->autLink[c - 'a'] = (v == &root ? &root : v->sufLink->autLink[c - 'a']);
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
        
        state = &root;
    }

    bool consume(char c) {
        state = state->autLink[c - 'a'];
        return state->isTerminal;
    }
};

class StreamChecker {
    Trie trie;
    
public:
    StreamChecker(vector<string> &words) {
        for (string &word : words)
            trie.add(word);
        trie.build(26);
    }
    
    bool query(char c) {
        return trie.consume(c);
    }
};