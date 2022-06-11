class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }
    
public:
    int minSteps(string a, string b) {
        vector<int> countA = getCount(a);
        vector<int> countB = getCount(b);
        
        int res = 0;
        for (int i = 0; i < countA.size(); i++)
            res += abs(countA[i] - countB[i]);
        
        return res / 2;
    }
};