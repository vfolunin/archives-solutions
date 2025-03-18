struct Trie {
    struct Node {
        map<char, Node> next;
        int pathCount = 0;
    } root;
    vector<multiset<int>> pathCounts;

    void insert(const string &s) {
        Node *n = &root;
        for (int i = 0; i < s.size(); i++) {
            n = &n->next[s[i]];
            if (pathCounts.size() == i)
                pathCounts.emplace_back();
            if (auto it = pathCounts[i].find(n->pathCount); it != pathCounts[i].end())
                pathCounts[i].erase(it);
            n->pathCount++;
            pathCounts[i].insert(n->pathCount);
        }
    }

    void erase(const string &s) {
        Node *n = &root;
        for (int i = 0; i < s.size(); i++) {
            n = &n->next[s[i]];
            if (auto it = pathCounts[i].find(n->pathCount); it != pathCounts[i].end())
                pathCounts[i].erase(it);
            n->pathCount--;
            pathCounts[i].insert(n->pathCount);
        }
    }
    
    int getLcp(int threshold) {
        int l = 0, r = pathCounts.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (*pathCounts[m - 1].rbegin() >= threshold)
                l = m;
            else
                r = m;
        }
        return l;
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string> &words, int threshold) {
        Trie trie;
        for (string &word : words)
            trie.insert(word);

        vector<int> res(words.size());
        for (int i = 0; i < res.size(); i++) {
            trie.erase(words[i]);
            res[i] = trie.getLcp(threshold);
            trie.insert(words[i]);
        }
        return res;
    }
};