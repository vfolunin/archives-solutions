class Solution {
public:
    int removeDuplicates(vector<int> &a) {
        int to = 0;
        for (int from = 0; from < a.size(); from++) {
            if (from < 2 || a[to - 2] != a[from]) {
                a[to] = a[from];
                to++;
            }
        }
        return to;
    }
};