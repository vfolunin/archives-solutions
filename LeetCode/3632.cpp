struct Trie {
    struct Node {
        vector<Node *> next;
        Node() : next(2) {}
        int size = 0;
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
    
    int getCount(int value, int threshold) {
        Node *n = &root;
        int res = 0;
        for (int bit = 30; bit >= 0 && n; bit--) {
            int thresholdBitValue = (threshold >> bit) & 1;
            int bitValue = (value >> bit) & 1;
            if (thresholdBitValue) {
                if (n->next[bitValue])
                    res += n->next[bitValue]->size;
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
    long long countXorSubarrays(vector<int> &a, int threshold) {
        long long res = 0;

        int xorSum = 0;
        Trie trie;
        trie.insert(xorSum);

        for (int i = 0; i < a.size(); i++) {
            xorSum ^= a[i];
            res += i + 1 - trie.getCount(xorSum, threshold);
            trie.insert(xorSum);
        }

        return res;
    }
};