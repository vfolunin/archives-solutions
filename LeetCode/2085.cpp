class Solution {
public:
    int countWords(vector<string> &a, vector<string> &b) {
        unordered_map<string, int> countA;
        for (string &s : a)
            countA[s]++;
        
        unordered_map<string, int> countB;
        for (string &s : b)
            countB[s]++;
        
        int res = 0;
        for (auto &[s, count] : countA)
            if (count == 1)
                res += countB[s] == 1;
        
        return res;
    }
};