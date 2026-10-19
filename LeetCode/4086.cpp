class Solution {
public:
    int minSelection(vector<vector<int>> &segmentsA, vector<vector<int>> &segmentsB) {
        map<int, int> deltas;
        for (vector<int> &segment : segmentsB) {
            deltas[segment[0] * 2]++;
            deltas[segment[1] * 2 + 1]--;
        }

        sort(segmentsA.begin(), segmentsA.end());

        int segmentCount = 0, to = -1, res = 0;
        for (int i = 0, ai = 0; i < deltas.size(); i++) {
            segmentCount += deltas[i];
            if (segmentCount && to < i) {
                for (; ai < segmentsA.size() && segmentsA[ai][0] * 2 <= i; ai++)
                    to = max(to, segmentsA[ai][1] * 2);
                if (to < i)
                    return -1;
                res++;
            }
        }
        return res;
    }
};