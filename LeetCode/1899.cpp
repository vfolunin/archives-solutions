class Solution {
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        vector<int> found(3);
        for (vector<int> &triplet : triplets) {
            found[0] |= triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2];
            found[1] |= triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2];
            found[2] |= triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2];
        }
        return found[0] && found[1] && found[2];
    }
};