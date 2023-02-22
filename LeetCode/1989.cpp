class Solution {
public:
    int catchMaximumAmountofPeople(vector<int> &a, int dist) {
        int res = 0;
        
        for (int i0 = 0, i1 = 0; i0 < a.size() && i1 < a.size(); ) {
            while (i0 < i1 - dist || i0 < a.size() && a[i0])
                i0++;
            while (i1 < i0 - dist || i1 < a.size() && !a[i1])
                i1++;

            if (i0 < a.size() && i1 < a.size() && abs(i0 - i1) <= dist) {
                i0++;
                i1++;
                res++;
            }
        }

        return res;
    }
};