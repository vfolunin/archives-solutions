class Solution {
public:
    int countGoodTriplets(vector<int> &a, int ij, int jk, int ik) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (abs(a[i] - a[j]) <= ij)
                    for (int k = j + 1; k < a.size(); k++)
                        res += abs(a[j] - a[k]) <= jk && abs(a[i] - a[k]) <= ik;
        return res;
    }
};