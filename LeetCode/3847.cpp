class Solution {
public:
    int scoreDifference(vector<int> &a) {
        vector<int> score(2);
        int player = 0;

        for (int i = 0; i < a.size(); i++) {
            if ((a[i] % 2) ^ (i % 6 == 5))
                player ^= 1;
            score[player] += a[i];
        }

        return score[0] - score[1];
    }
};