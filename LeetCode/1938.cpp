struct Trie {
    struct Node {
        map<char, Node> next;
        int count = 0;
    } root;

    void insert(int val, int delta) {
        Node *n = &root;
        for (int bit = 17; bit >= 0; bit--) {
            n = &n->next[(val >> bit) & 1];
            n->count += delta;
        }
    }
    
    int getMaxXor(int val) {
        Node *n = &root;
        int res = 0;
        for (int bit = 17; bit >= 0; bit--) {
            int bitValue = (val >> bit) & 1;
            if (n->next[bitValue ^ 1].count) {
                res |= 1 << bit;
                n = &n->next[bitValue ^ 1];
            } else {
                n = &n->next[bitValue];
            }
        }
        return res;
    }
};

class Solution {
    void dfs(vector<vector<int>> &graph, int v, Trie &trie,
             vector<vector<int>> &queries, vector<vector<int>> &queriesOf) {
        trie.insert(v, 1);
        
        for (int i : queriesOf[v])
            queries[i].push_back(trie.getMaxXor(queries[i][1]));
        
        for (int to : graph[v])
            dfs(graph, to, trie, queries, queriesOf);
        
        trie.insert(v, -1);
    }
    
public:
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries) {
        int root;
        vector<vector<int>> graph(parents.size());
        for (int v = 0; v < parents.size(); v++) {
            if (parents[v] == -1)
                root = v;
            else
                graph[parents[v]].push_back(v);
        }
        
        Trie trie;
        
        vector<vector<int>> queriesOf(graph.size());
        for (int i = 0; i < queries.size(); i++)
            queriesOf[queries[i][0]].push_back(i);
        
        dfs(graph, root, trie, queries, queriesOf);
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = queries[i][2];
        return res;
    }
};