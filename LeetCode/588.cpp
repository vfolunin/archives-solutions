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
        string content;
    } root;

    void insert(const vector<string> &path, const string &content) {
        Node *n = &root;
        for (int i = 0; i < path.size(); i++)
            n = &n->next[path[i]];
        n->content += content;
    }
    
    string getContent(const vector<string> &path) {
        Node *n = &root;
        for (int i = 0; i < path.size(); i++)
            n = &n->next[path[i]];
        return n->content;
    }
    
    vector<string> getChildren(const vector<string> &path) {
        Node *n = &root;
        for (int i = 0; i < path.size(); i++)
            n = &n->next[path[i]];

        if (!n->content.empty())
            return { path.back() };
        
        vector<string> children;
        for (auto &[s, to] : n->next)
            children.push_back(s);
        return children;
    }
};

class FileSystem {
    Trie trie;

public:
    vector<string> ls(const string &path) {
        return trie.getChildren(split(path, "/"));
    }
    
    void mkdir(const string &path) {
        trie.insert(split(path, "/"), "");
    }
    
    void addContentToFile(const string &path, string content) {
        trie.insert(split(path, "/"), content);        
    }
    
    string readContentFromFile(const string &path) {
        return trie.getContent(split(path, "/"));
    }
};