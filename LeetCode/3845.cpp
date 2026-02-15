struct Trie {
    struct Node {
        vector<Node *> next;
        Node() : next(2) {}
        int size = 0;
    } root;

    void add(int value, int delta) {
        Node *n = &root;
        for (int bit = 30; bit >= 0; bit--) {
            if (!n->next[(value >> bit) & 1])
                n->next[(value >> bit) & 1] = new Node;
            n = n->next[(value >> bit) & 1];
            n->size += delta;
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
            } else {
                n = n->next[bitValue];
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxXor(vector<int> &a, int limit) {
        vector<int> prefixXor(1);
        for (int value : a)
            prefixXor.push_back(prefixXor.back() ^ value);

        Trie trie;
        multiset<int> values;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            trie.add(prefixXor[r], 1);
            values.insert(a[r]);

            while (*prev(values.end()) - *values.begin() > limit) {
                trie.add(prefixXor[l], -1);
                values.erase(values.find(a[l]));
                l++;
            }
            
            res = max(res, trie.getMaxXor(prefixXor[r + 1]));
        }

        return res;
    }
};