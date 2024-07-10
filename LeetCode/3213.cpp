struct Trie {
    struct Node {
        map<char, Node> next;
        int price = 1e9;
    } root;

    void insert(string &s, int price) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->price = min(n->price, price);
    }
};

class Solution {
public:
    int minimumCost(string &target, vector<string> &words, vector<int> &prices) {
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], prices[i]);
        
        vector<int> cost(target.size() + 1, 1e9);
        cost[0] = 0;

        for (int size = 0; size < target.size(); size++) {
            Trie::Node *node = &trie.root;
            for (int i = size; i < target.size() && node->next.count(target[i]); i++) {
                node = &node->next[target[i]];
                cost[i + 1] = min(cost[i + 1], cost[size] + node->price);
            }
        }

        return cost.back() < 1e9 ? cost.back() : -1;
    }
};