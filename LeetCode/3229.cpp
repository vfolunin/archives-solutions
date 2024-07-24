class Solution {
public:
    long long minimumOperations(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < a.size(); i++)
            a[i] = b[i] - a[i];
        
        long long res = 0;
        int up = 0, down = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0) {
                res += max(a[i] - up, 0);
                up = a[i];
                down = 0;
            } else if (a[i] < 0) {
                res += max(down - a[i], 0);
                up = 0;
                down = a[i];
            } else {
                up = down = 0;
            }
        }
        
        return res;
    }
};