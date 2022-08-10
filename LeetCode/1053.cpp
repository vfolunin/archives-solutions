class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                int j = a.size() - 1;
                while (a[i] <= a[j] || a[j - 1] == a[j])
                    j--;
                swap(a[i], a[j]);
                break;
            }
        }
        return a;
    }
};