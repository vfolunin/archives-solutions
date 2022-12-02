struct Trie {
    struct Node {
        map<string, Node> next;
        bool removed = 0;
    } root;

    void insert(vector<string> &path) {
        Node *n = &root;
        for (string &folder : path)
            n = &n->next[folder];
    }
    
    string markRemoved(Node *n, unordered_map<string, Node *> &seen) {
        string s = "(";
        for (auto &[folder, to] : n->next)
            s += folder + markRemoved(&to, seen);
        s += ")";
        
        if (s != "()") {
            if (seen.count(s))
                n->removed = seen[s]->removed = 1;
            else
                seen[s] = n;
        }
        
        return s;
    }
    
    void markRemoved() {
        unordered_map<string, Node *> seen;
        markRemoved(&root, seen);
    }
    
    void dfs(Node *n, vector<string> &path, vector<vector<string>> &paths) {
        if (n->removed)
            return;
        
        if (!path.empty())
            paths.push_back(path);
        
        for (auto &[folder, to] : n->next) {
            path.push_back(folder);
            dfs(&to, path, paths);
            path.pop_back();
        }
    }
    
    vector<vector<string>> dfs() {
        vector<string> path;
        vector<vector<string>> paths;
        dfs(&root, path, paths);
        return paths;
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
        Trie trie;
        for (vector<string> &path : paths)
            trie.insert(path);
        
        trie.markRemoved();
        
        return trie.dfs();
    }
};