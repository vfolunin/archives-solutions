class Solution {
public:
    vector<int> maximumMEX(vector<int> &a) {
        vector<vector<int>> pos(1e5 + 1);
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        vector<int> posI(pos.size()), res;
        for (int i = 0; i < a.size(); ) {
            int mex = 0, nextI = i + 1;
            for (; posI[mex] < pos[mex].size(); mex++)
                nextI = max(nextI, pos[mex][posI[mex]] + 1);
            res.push_back(mex);

            for (int value = 0; value < mex; value++)
                while (posI[value] < pos[value].size() && pos[value][posI[value]] < nextI)
                    posI[value]++;
            i = nextI;
        }
        return res;
    }
};