struct Trie {
    struct Node {
        map<char, Node> next;
        int size = 0;
    } root;

    void insert(const string &s) {
        Node *n = &root;
        for (char c : s) {
            n = &n->next[c];
            n->size++;
        }
    }
    
    int getSum(const string &s) {
        Node *n = &root;
        int sum = 0;
        for (char c : s) {
            if (!n->next.count(c))
                break;
            n = &n->next[c];
            sum += n->size;
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        Trie trie;
        for (string &word : words)
            trie.insert(word);
        
        vector<int> res(words.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = trie.getSum(words[i]);
        return res;
    }
};