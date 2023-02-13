vector<string> split(const string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

struct Trie {
    struct Node {
        map<string, Node> next;
        int value = 0;
    } root;

    bool insert(const vector<string> &path, int value) {
        Node *n = &root;
        for (int i = 0; i + 1 < path.size(); i++) {
            if (!n->next.count(path[i]))
                return 0;
            n = &n->next[path[i]];
        }

        if (n->next.count(path.back()))
            return 0;

        n = &n->next[path.back()];
        n->value = value;
        return 1;
    }
    
    int get(const vector<string> &path) {
        Node *n = &root;
        for (const string &dir : path) {
            if (!n->next.count(dir))
                return -1;
            n = &n->next[dir];
        }
        return n->value;
    }
};

class FileSystem {
    Trie trie;

public:    
    bool createPath(const string &path, int value) {
        return trie.insert(split(path, "/"), value);
    }
    
    int get(const string &path) {
        return trie.get(split(path, "/"));
    }
};