struct Trie {
    struct Node {
        map<char, Node> next;
        int index = -1;
    } root;
    
    void insert(const string &s, int index) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->index = index;
    }
};

class Solution {
    void rec(vector<vector<char>> &a, int y, int x, Trie::Node *n, unordered_set<int> &indexes) {
        if (n->index != -1)
            indexes.insert(n->index);
        
        char c = a[y][x];
        a[y][x] = ' ';
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && n->next.count(a[ty][tx]))
                rec(a, ty, tx, &n->next[a[ty][tx]], indexes);
        }
        
        a[y][x] = c;        
    }
    
public:
    vector<string> findWords(vector<vector<char>> &a, vector<string> &words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);
        
        unordered_set<int> indexes;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (trie.root.next.count(a[y][x]))
                    rec(a, y, x, &trie.root.next[a[y][x]], indexes);
        
        vector<string> res;
        for (int index : indexes)
            res.push_back(words[index]);
        return res;
    }
};