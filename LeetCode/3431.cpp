class Solution {
public:
    int minUnlockedIndices(vector<int> &a, vector<int> &locked) {
        int last1 = -1, first2 = a.size(), last2 = -1, first3 = a.size();
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1) {
                last1 = max(last1, i);
            } else if (a[i] == 2) {
                first2 = min(first2, i);
                last2 = max(last2, i);
            } else {
                first3 = min(first3, i);
            }
        }

        if (first3 < last1)
            return -1;
        
        int res = 0;
        for (int i = first2; i < last1; i++) {
            res += locked[i];
            locked[i] = 0;
        }
        for (int i = first3; i < last2; i++) {
            res += locked[i];
            locked[i] = 0;
        }
        return res;
    }
};