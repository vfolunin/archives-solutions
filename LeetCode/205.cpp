class Solution {    
public:
    bool isIsomorphic(string a, string b) {
        unordered_map<char, char> ab, ba;
        for (int i = 0; i < a.size(); i++) {
            if (!ab.count(a[i]) && !ba.count(b[i])) {
                ab[a[i]] = b[i];
                ba[b[i]] = a[i];
            } else if (ab[a[i]] != b[i] || ba[b[i]] != a[i]) {
                return 0;
            }
        }
        return 1;
    }
};