class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;
        
        vector<int> a(children, 1);
        money -= children;

        for (int i = 0; i < a.size(); i++) {
            if (money >= 7) {
                money -= 7;
                a[i] += 7;
            }
        }
        
        if (money) {
            a.back() += money;
            if (a.back() == 4) {
                a.back()--;
                a[a.size() - 2]++;
            }
        }
        
        return count(a.begin(), a.end(), 8);
    }
};