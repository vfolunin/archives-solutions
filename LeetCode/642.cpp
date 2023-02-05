struct Trie {
    struct Node {
        map<char, Node> next;
        unordered_map<string, int> count;
        set<pair<int, string>> pairs;

        void add(string &word, int delta) {
            pairs.erase({ -count[word], word });
            count[word] += delta;
            pairs.insert({ -count[word], word });
        }
    } root, *cur;

    void insert(string &word, int delta) {
        Node *n = &root;
        for (char c : word) {
            n->add(word, delta);
            n = &n->next[c];
        }
        n->add(word, delta);
    }

    void reset() {
        cur = &root;
    }
    
    vector<string> getSuggestions(char c) {
        cur = &cur->next[c];
        vector<string> res;
        for (auto &[count, word] : cur->pairs) {
            res.push_back(word);
            if (res.size() == 3)
                break;
        }
        return res;
    }
};

class AutocompleteSystem {
    Trie trie;
    string word;

public:
    AutocompleteSystem(vector<string> &words, vector<int> &deltas) {
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], deltas[i]);
        trie.reset();
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie.insert(word, 1);
            trie.reset();
            word.clear();
            return {};
        } else {
            word += c;
            return trie.getSuggestions(c);
        }
    }
};