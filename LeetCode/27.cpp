class Solution {
public:
    int removeElement(vector<int> &a, int value) {
        int to = 0;
        for (int from = 0; from < a.size(); from++) {
            if (a[from] != value) {
                a[to] = a[from];
                to++;
            }
        }
        return to;
    }
};