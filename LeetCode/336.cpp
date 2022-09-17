bool isPalindrome(const string &s, int l, int r) {
    for ( ; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

struct Trie {
    struct Node {
        vector<Node *> next;
        int index = -1;
        vector<int> palindromeIndexes;
        
        Node() : next(26) {}
    } *root;
    
    Trie() {
        root = new Node;
    }

    void insert(const string &s, int index) {
        Node *n = root;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isPalindrome(s, 0, i))
                n->palindromeIndexes.push_back(index);
            
            if (!n->next[s[i] - 'a'])
                n->next[s[i] - 'a'] = new Node;
            n = n->next[s[i] - 'a'];
        }
        
        n->index = index;
        n->palindromeIndexes.push_back(index);
    }

    vector<int> search(const string &s) {
        vector<int> res;
        Node *n = root;

        for (int i = 0; n && i < s.size(); i++) {
            if (n->index != -1 && isPalindrome(s, i, s.size() - 1))
                res.push_back(n->index);

            n = n->next[s[i] - 'a'];
        }

        if (n)
            res.insert(res.end(), n->palindromeIndexes.begin(), n->palindromeIndexes.end());

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++)
            for (int j : trie.search(words[i]))
                if (i != j)
                    res.push_back({ i, j });
        return res;
    }
};