struct Trie {
    struct Node {
        map<pair<char, char>, Node> next;
        int count = 0;
    } root;

    int insert(const string &s) {
        Node *n = &root;
        int res = 0;
        for (int l = 0, r = s.size() - 1; l < s.size(); l++, r--) {
            n = &n->next[{ s[l], s[r] }];
            res += n->count;
        }
        n->count++;
        return res;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string> &a) {
        Trie trie;
        long long res = 0;

        for (string &s : a)
            res += trie.insert(s);
        
        return res;
    }
};