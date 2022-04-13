class Solution {
public:
    int removeDuplicates(vector<int> &a) {
        int to = 0;
        for (int from = 0; from < a.size(); from++) {
            if (!from || a[from - 1] != a[from]) {
                a[to] = a[from];
                to++;
            }
        }
        return to;
    }
};