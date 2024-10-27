class Solution {
public:
    int maxScore(int vertexCount, int dayCount, vector<vector<int>> &stay, vector<vector<int>> &travel) {
        vector<vector<int>> score(dayCount, vector<int>(vertexCount));

        for (int v = 0; v < vertexCount; v++) {
            score[0][v] = max(score[0][v], stay[0][v]);
            for (int p = 0; p < vertexCount; p++)
                score[0][v] = max(score[0][v], travel[p][v]);
        }

        for (int day = 1; day < dayCount; day++) {
            for (int v = 0; v < vertexCount; v++) {
                score[day][v] = max(score[day][v], score[day - 1][v] + stay[day][v]);
                for (int p = 0; p < vertexCount; p++)
                    score[day][v] = max(score[day][v], score[day - 1][p] + travel[p][v]);
            }
        }

        return *max_element(score.back().begin(), score.back().end());
    }
};