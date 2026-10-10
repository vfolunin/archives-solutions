class Trie {
    struct Vertex {
        unordered_map<char, Vertex> next;
        vector<int> indexes;
        int index = -1;
    } root;

    int dfs(Vertex *v) {
        int res = 0;

        vector<Vertex *> tos;
        for (auto &[c, to] : v->next) {
            res += dfs(&to);
            tos.push_back(&to);
        }

        if (v->index != -1)
            for (Vertex *to : tos)
                for (int toIndex : to->indexes)
                    res += v->index > toIndex;

        if (tos.size() > 1) {
            for (Vertex *to : tos)
                sort(to->indexes.begin(), to->indexes.end());

            vector<vector<int>> cost(tos.size(), vector<int>(tos.size()));
            for (int ai = 0; ai < tos.size(); ai++) {
                for (int bi = 0; bi < tos.size(); bi++) {
                    if (ai == bi)
                        continue;

                    for (int aj = 0, bj = 0; aj < tos[ai]->indexes.size(); aj++) {
                        while (bj < tos[bi]->indexes.size() && tos[ai]->indexes[aj] > tos[bi]->indexes[bj])
                            bj++;
                        cost[ai][bi] += bj;
                    }
                }
            }

            vector<int> minCost(1 << tos.size(), 1e9);
            minCost[0] = 0;

            for (int mask = 1; mask < (int)minCost.size(); mask++) {
                for (int ai = 0; ai < tos.size(); ai++) {
                    if (!(mask & (1 << ai)))
                        continue;

                    int prevMask = mask - (1 << ai);
                    if (minCost[prevMask] == 1e9)
                        continue;

                    int candidateCost = minCost[prevMask];
                    for (int bi = 0; bi < tos.size(); bi++)
                        if (mask & (1 << bi) && ai != bi)
                            candidateCost += cost[bi][ai];

                    minCost[mask] = min(minCost[mask], candidateCost);
                }
            }

            res += minCost.back();
        }

        return res;
    }

public:
    void insert(string &s, int index) {
        Vertex *v = &root;
        for (char c : s) {
            v = &v->next[c];
            v->indexes.push_back(index);
        }
        v->index = index;
    }

    int dfs() {
        return dfs(&root);
    }
};

class Solution {
public:
    int minInversions(vector<string> &words, vector<int> &target) {
        vector<int> index(words.size());
        for (int i = 0; i < words.size(); i++)
            index[target[i]] = i;

        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], index[i]);
        return trie.dfs();
    }
};