class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &a) {
        for (int i0 = 0, i1 = 1; i0 < a.size() && i1 < a.size(); i0 += 2, i1 += 2) {
            while (i0 < a.size() && a[i0] % 2 == 0)
                i0 += 2;
            while (i1 < a.size() && a[i1] % 2 != 0)
                i1 += 2;
            if (i0 < a.size() && i1 < a.size())
                swap(a[i0], a[i1]);
        }
        return a;
    }
};