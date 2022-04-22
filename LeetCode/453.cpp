class Solution {
public:
    int minMoves(vector<int> &a) {
        int minValue = *min_element(a.begin(), a.end()), res = 0;
        for (int value : a)
            res += value - minValue;
        return res;
    }
};