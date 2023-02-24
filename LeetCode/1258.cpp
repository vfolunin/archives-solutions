struct Compressor {
    unordered_map<string, int> ids;

    int getId(string &word) {
        if (!ids.count(word))
            ids[word] = ids.size();
        return ids[word];
    }
};

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
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
    }
};

class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }

    string join(vector<string> &words) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }

    void rec(vector<int> &groupIds, int i, vector<set<string>> &groups, vector<string> &sentence, vector<string> &res) {
        if (i == groupIds.size()) {
            res.push_back(join(sentence));
            return;
        }
        for (const string &word : groups[groupIds[i]]) {
            sentence[i] = word;
            rec(groupIds, i + 1, groups, sentence, res);
        }
    }

public:
    vector<string> generateSentences(vector<vector<string>> &edges, string &line) {
        Compressor compressor;
        DSU dsu(100);

        for (vector<string> &edge : edges)
            dsu.merge(compressor.getId(edge[0]), compressor.getId(edge[1]));

        vector<string> words = split(line);
        vector<int> groupIds;
        for (string &word : words)
            groupIds.push_back(dsu.find(compressor.getId(word)));
        
        vector<set<string>> groups(100);
        for (auto &[word, id] : compressor.ids)
            groups[dsu.find(id)].insert(word);
        
        vector<string> sentence(groupIds.size()), res;
        rec(groupIds, 0, groups, sentence, res);
        return res;
    }
};