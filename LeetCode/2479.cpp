struct Trie {
    struct Node {
        vector<Node *> next;
        Node() : next(2) {}
    } root;

    void insert(long long value) {
        Node *n = &root;
        for (int bit = 60; bit >= 0; bit--) {
            if (!n->next[(value >> bit) & 1])
                n->next[(value >> bit) & 1] = new Node;
            n = n->next[(value >> bit) & 1];
        }
    }
    
    long long getMaxXor(long long value) {
        Node *n = &root;
        long long res = 0;
        for (int bit = 60; bit >= 0; bit--) {
            int bitValue = (value >> bit) & 1;
            if (n->next[bitValue ^ 1]) {
                res |= 1LL << bit;
                n = n->next[bitValue ^ 1];
            } else if (n->next[bitValue]) {
                n = n->next[bitValue];
            } else {
                return 0;
            }
        }
        return res;
    }
};

class Solution {
    long long dfs1(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &values, vector<long long> &sums) {
        visited[v] = 1;
        sums[v] = values[v];

        for (int to : graph[v])
            if (!sums[to])
                sums[v] += dfs1(graph, to, visited, values, sums);

        return sums[v];
    }

    long long dfs2(vector<vector<int>> &graph, int v, vector<int> &visited, Trie &trie, vector<long long> &sums) {
        visited[v] = 1;
        long long res = trie.getMaxXor(sums[v]);

        for (int to : graph[v])
            if (!visited[to])
                res = max(res, dfs2(graph, to, visited, trie, sums));

        trie.insert(sums[v]);
        return res;
    }

public:
    long long maxXor(int vertexCount, vector<vector<int>> &edges, vector<int> &values) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(vertexCount);
        vector<long long> sums(vertexCount);
        dfs1(graph, 0, visited, values, sums);

        visited.assign(vertexCount, 0);
        Trie trie;
        return dfs2(graph, 0, visited, trie, sums);
    }
};