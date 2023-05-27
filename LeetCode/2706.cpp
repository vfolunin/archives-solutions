class Solution {
public:
    int buyChoco(vector<int> &a, int money) {
        sort(a.begin(), a.end());
        if (a[0] + a[1] <= money)
            money -= a[0] + a[1];
        return money;
    }
};