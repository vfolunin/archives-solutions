class Solution {
public:
    void moveZeroes(vector<int> &a) {
        for (int from = 0, to = 0; from < a.size(); from++) {
            if (a[from]) {
                swap(a[to], a[from]);
                to++;
            }
        }
    }
};