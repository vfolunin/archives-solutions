struct Hasher {
    long long factor, mod;
    vector<long long> p;

    Hasher(long long factor, long long mod, int size) : factor(factor), mod(mod) {
        p.push_back(1);
        for (int i = 1; i < size; i++)
            p.push_back(p.back() * factor % mod);
    }

    long long getHash(string &s) {
        long long hash = 0;
        for (int i = 0; i < s.size(); i++)
            hash = (hash + (s[i] - 'a' + 1) * p[i]) % mod;
        return hash;
    }

    long long modifyHash(long long hash, string &s, int i) {
        return ((hash - (s[i] - 'a' + 1) * p[i]) % mod + mod) % mod;
    }
};

class Solution {
public:
    bool differByOne(vector<string> &words) {
        Hasher hasherA(29, 1e9 + 7, words[0].size());
        Hasher hasherB(31, 1e9 + 9, words[0].size());

        set<pair<long long, long long>> hashes;
        for (string &word : words) {
            long long ha = hasherA.getHash(word);
            long long hb = hasherB.getHash(word);
            
            for (int i = 0; i < word.size(); i++) {
                long long ma = hasherA.modifyHash(ha, word, i);
                long long mb = hasherB.modifyHash(hb, word, i);

                if (hashes.count({ ma, mb }))
                    return 1;
                hashes.insert({ ma, mb });
            }
        }
        
        return 0;
    }
};