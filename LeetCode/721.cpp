struct Compressor {
    unordered_map<string, int> ids;
    vector<string> words;

    int getId(string &word) {
        if (!ids.count(word)) {
            ids[word] = ids.size();
            words.push_back(word);
        }
        return ids[word];
    }

    string getWord(int id) {
        return words[id];
    }
    
    int size() {
        return ids.size();
    }
};

struct DSU {
    vector<int> id;
    vector<int> minValue;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        minValue = id;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        minValue[ri] = minValue[rj] = min(minValue[ri], minValue[rj]);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        Compressor compressor;
        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
                compressor.getId(accounts[i][j]);
        
        DSU dsu(accounts.size() + compressor.size());
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                int v = accounts.size() + compressor.getId(accounts[i][j]);
                dsu.merge(i, v);
            }
        }
        
        unordered_map<int, set<string>> resMap;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                int v = accounts.size() + compressor.getId(accounts[i][j]);
                int index = dsu.minValue[dsu.find(v)];
                resMap[index].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> res;
        for (auto &[index, emails] : resMap) {
            res.push_back({ accounts[index][0] });
            res.back().insert(res.back().end(), emails.begin(), emails.end());
        }
        return res;
    }
};