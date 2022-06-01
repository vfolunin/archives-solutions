class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }
    
public:
    int rearrangeCharacters(string a, string b) {
        vector<int> countA = getCount(a), countB = getCount(b);
        int res = 1e9;
        for (int i = 0; i < countA.size(); i++)
            if (countB[i])
                res = min(res, countA[i] / countB[i]);
        return res;
    }
};