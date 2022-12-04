struct Trie {
    struct Node {
        vector<Node *> next;
        Node() : next(2) {}
    } root;

    void insert(int value) {
        Node *n = &root;
        for (int bit = 30; bit >= 0; bit--) {
            if (!n->next[(value >> bit) & 1])
                n->next[(value >> bit) & 1] = new Node;
            n = n->next[(value >> bit) & 1];
        }
    }
    
    int getMaxXor(int value) {
        Node *n = &root;
        int res = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int bitValue = (value >> bit) & 1;
            if (n->next[bitValue ^ 1]) {
                res |= 1 << bit;
                n = n->next[bitValue ^ 1];
            } else if (n->next[bitValue]) {
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
    vector<int> maximizeXor(vector<int> &a, vector<vector<int>> &queries) {
        sort(a.begin(), a.end());
        
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        
        int ai = 0;
        Trie trie;
        vector<int> res(queries.size(), -1);
        
        for (int qi : order) {
            while (ai < a.size() && a[ai] <= queries[qi][1])
                trie.insert(a[ai++]);
            res[qi] = trie.getMaxXor(queries[qi][0]);
        }
        
        return res;
    }
};