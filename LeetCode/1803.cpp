struct Trie {
    struct Node {
        map<char, Node> next;
        int count = 0;
    } root;

    void insert(int val) {
        Node *n = &root;
        for (int bit = 20; bit >= 0; bit--) {
            n = &n->next[(val >> bit) & 1];
            n->count++;
        }
    }
    
    int getCount(int val, int limit) {
        Node *n = &root;
        int res = 0;
        for (int bit = 20; bit >= 0; bit--) {
            int a = (val >> bit) & 1, b = (limit >> bit) & 1;
            if (n->next.count(a) && b)
                res += n->next[a].count;
            if (!n->next.count(a ^ b))
                break;
            n = &n->next[a ^ b];
        }
        return res;
    }
};

class Solution {
public:
    int countPairs(vector<int> &a, int l, int r) {
        Trie trie;
        int res = 0;
        for (int value : a) {
            res += trie.getCount(value, r + 1) - trie.getCount(value, l);
            trie.insert(value);
        }
        return res;
    }
};