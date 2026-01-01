class Solution {
public:
    int rec(int i, int ops, int time, vector<int> &signPos, vector<int> &signTime, vector<vector<vector<int>>> &memo) {
        int &res = memo[i][ops][time];
        if (res != -1)
            return res;

        if (i == signPos.size() - 1)
            return res = ops ? 1e9 : 0;

        res = (signPos[i + 1] - signPos[i]) * time + rec(i + 1, ops, signTime[i + 1], signPos, signTime, memo);

        if (ops) {
            int nextI = i + 1;
            int nextTime = signTime[nextI];

            for (int nextOps = ops - 1; nextOps >= 0 && nextI + 1 < signTime.size(); nextOps--) {
                nextI++;
                nextTime += signTime[nextI];
                res = min(res, (signPos[nextI] - signPos[i]) * time + rec(nextI, nextOps, nextTime, signPos, signTime, memo));
            }
        }

        return res;
    }

    int minTravelTime(int length, int signCount, int opCount, vector<int> &signPos, vector<int> &signTime) {
        vector memo(signCount + 1, vector(opCount + 1, vector<int>(101, -1)));
        return rec(0, opCount, signTime[0], signPos, signTime, memo);
    }
};
