class Solution {
public:
    int countQuadruplets(vector<int> &a) {
        int res = 0;
        for (int i1 = 0; i1 < a.size(); i1++) {
            for (int i2 = i1 + 1; i2 < a.size(); i2++) {
                vector<int> count(101);
                for (int i3 = i2 + 1; i3 < a.size(); i3++)
                    count[a[i3]]++;
                
                for (int i3 = i2 + 1; i3 < a.size(); i3++) {
                    count[a[i3]]--;
                    if (a[i1] + a[i2] + a[i3] < count.size())
                        res += count[a[i1] + a[i2] + a[i3]];
                }
            }
        }
        return res;
    }
};