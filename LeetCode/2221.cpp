class Solution {
public:
    int triangularSum(vector<int> &a) {
        while (a.size() > 1) {
            vector<int> nextA(a.size() - 1);
            for (int i = 0; i < nextA.size(); i++)
                nextA[i] = (a[i] + a[i + 1]) % 10;
            a.swap(nextA);
        }
        return a[0];
    }
};