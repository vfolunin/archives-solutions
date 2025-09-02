class Solution {
    void rec(int size, vector<int> &a, vector<int> &used, vector<vector<int>> &res) {
        if (a.size() == size) {
            res.push_back(a);
            return;
        }

        for (int i = 1; i <= size; i++) {
            if ((a.empty() || a.back() % 2 != i % 2) && !used[i]) {
                a.push_back(i);
                used[i] = 1;

                rec(size, a, used, res);

                a.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(int size) {
        vector<int> a, used(size + 1);
        vector<vector<int>> res;
        rec(size, a, used, res);
        return res;
    }
};