class Trie {
    struct Vertex {
        bool isTerminal = false;
        map<char, Vertex> next;
        Vertex *sufLink = nullptr;
        map<char, Vertex *> autLink;
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
                to.sufLink = (v == &root ? &root : v->sufLink->autLink[c]);                
                q.push(&to);
            }

            for (char c = 'a'; c < 'a' + alphabetSize; c++) {
                if (v->next.count(c))
                    v->autLink[c] = &v->next[c];
                else
                    v->autLink[c] = (v == &root ? &root : v->sufLink->autLink[c]);
            }

            v->isTerminal |= v->sufLink->isTerminal;
        }
        
        state = &root;
    }

    bool consume(char c) {
        state = state->autLink[c];
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