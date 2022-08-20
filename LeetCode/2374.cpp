class Solution {
public:
    int edgeScore(vector<int> &edges) {
        vector<long long> score(edges.size());
        for (int v = 0; v < score.size(); v++)
            score[edges[v]] += v;
        return max_element(score.begin(), score.end()) - score.begin();
    }
};