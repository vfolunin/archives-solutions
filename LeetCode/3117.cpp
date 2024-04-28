class SparseTable {
    function<int(int, int)> f;
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &a, function<int(int, int)> f) : f(f) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(f(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int get(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return f(st[level][l], st[level][r - levelWidth + 1]);
    }
};

class Solution {
public:
    int minimumValueSum(vector<int> &a, vector<int> &andSum) {
        SparseTable sparseTableAnd(a, [](int lhs, int rhs) {
            return lhs & rhs;
        });

        vector<vector<int>> res(andSum.size() + 1, vector<int>(a.size() + 1, 1e9));
        res[0][0] = 0;

        for (int partCount = 1; partCount <= andSum.size(); partCount++) {
            SparseTable sparseTableMin(res[partCount - 1], [](int lhs, int rhs) {
                return min(lhs, rhs);
            });

            for (int size = 1; size <= a.size(); size++) {
                int leftL = -1, leftR = size;
                while (leftL + 1 < leftR) {
                    int leftM = leftL + (leftR - leftL) / 2;
                    if (sparseTableAnd.get(leftM, size - 1) >= andSum[partCount - 1])
                        leftR = leftM;
                    else
                        leftL = leftM;
                }
                int left = leftR;

                int rightL = -1, rightR = size;
                while (rightL + 1 < rightR) {
                    int rightM = rightL + (rightR - rightL) / 2;
                    if (sparseTableAnd.get(rightM, size - 1) > andSum[partCount - 1])
                        rightR = rightM;
                    else
                        rightL = rightM;
                }
                int right = rightL;

                if (left <= right)
                    res[partCount][size] = min(res[partCount][size], sparseTableMin.get(left, right) + a[size - 1]);
            }
        }

        return res.back().back() != 1e9 ? res.back().back() : -1;
    }
};