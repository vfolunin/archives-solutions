struct Trie {
    struct Node {
        vector<Node *> next;
        int size = 0;
        Node() : next(2) {}
    } root;

    void insert(int value) {
        Node *n = &root;
        for (int bit = 30; bit >= 0; bit--) {
            if (!n->next[(value >> bit) & 1])
                n->next[(value >> bit) & 1] = new Node;
            n = n->next[(value >> bit) & 1];
            n->size++;
        }
    }

    void erase(int value) {
        Node *n = &root;
        for (int bit = 30; bit >= 0; bit--) {
            n = n->next[(value >> bit) & 1];
            n->size--;
        }
    }
    
    int getMaxXor(int value) {
        Node *n = &root;
        int res = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int bitValue = (value >> bit) & 1;
            if (n->next[bitValue ^ 1] && n->next[bitValue ^ 1]->size) {
                res |= 1 << bit;
                n = n->next[bitValue ^ 1];
            } else if (n->next[bitValue] && n->next[bitValue]->size) {
                n = n->next[bitValue];
            } else {
                return -1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int> &a) {
        sort(a.begin(), a.end());

        Trie trie;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            trie.insert(a[r]);
            while (a[l] * 2 < a[r]) {
                trie.erase(a[l]);
                l++;
            }
            res = max(res, trie.getMaxXor(a[r]));
        }

        return res;
    }
};