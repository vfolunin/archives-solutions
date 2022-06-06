class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        vector<int> seen(100);
        int res = 0;
        
        for (vector<int> &domino : dominoes) {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);
            res += seen[domino[0] * 10 + domino[1]];
            seen[domino[0] * 10 + domino[1]]++;
        }
        
        return res;
    }
};