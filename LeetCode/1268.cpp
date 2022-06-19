class Trie {
    struct Node {
        map<char, Node> next;
        set<string_view> suggest;
    } root;

public:
    void insert(const string_view &s) {
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            n->suggest.insert(s);
            if (n->suggest.size() > 3)
                n->suggest.erase(--n->suggest.end());
        }
    }
    
    vector<vector<string>> getSuggest(const string_view &s) {
        vector<vector<string>> res;
            
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            res.emplace_back(n->suggest.begin(), n->suggest.end());
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &words, string searchWord) {
        Trie trie;
        
        for (string &word : words)
            trie.insert(word);
        
        return trie.getSuggest(searchWord);
    }
};