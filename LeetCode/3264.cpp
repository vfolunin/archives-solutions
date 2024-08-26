class Solution {
public:
    vector<int> getFinalState(vector<int> &a, int opCount, int factor) {
        for (int i = 0; i < opCount; i++)
            *min_element(a.begin(), a.end()) *= factor;
        return a;
    }
};