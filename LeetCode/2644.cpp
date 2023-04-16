class Solution {
public:
    int maxDivScore(vector<int> &a, vector<int> &divisors) {
        sort(divisors.begin(), divisors.end());

        vector<int> score(divisors.size());
        for (int value : a)
            for (int i = 0; i < divisors.size(); i++)
                score[i] += value % divisors[i] == 0;
        
        return divisors[max_element(score.begin(), score.end()) - score.begin()];
    }
};