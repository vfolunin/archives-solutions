class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &a, int width) {
        int size = a.size();
        a.insert(a.end(), a.begin(), a.end());

        int cur = 1, res = cur >= width;
        for (int i = 1; i < size + width - 1; i++) {
            if (a[i - 1] != a[i])
                cur++;
            else
                cur = 1;
            res +=  cur >= width;
        }
        return res;
    }
};