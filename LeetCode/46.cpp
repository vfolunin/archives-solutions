class Solution {
public:
    vector<vector<int>> permute(vector<int> &a) {
        vector<vector<int>> permutations;
        sort(a.begin(), a.end());
        do {
            permutations.push_back(a);
        } while (next_permutation(a.begin(), a.end()));
        return permutations;
    }
};