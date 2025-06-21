class Solution {
public:
    int minSwaps(vector<int> &a) {
        vector<int> oddPos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] % 2)
                oddPos.push_back(i);
        
        int res = 2e9;

        if (a.size() % 2 && oddPos.size() == (a.size() + 1) / 2 ||
            a.size() % 2 == 0 && oddPos.size() == a.size() / 2) {
            int to = 0, cur = 0;
            for (int from : oddPos) {
                cur += abs(from - to);
                to += 2;
            }
            res = min(res, cur);
        }

        if (oddPos.size() == a.size() / 2) {
            int to = 1, cur = 0;
            for (int from : oddPos) {
                cur += abs(from - to);
                to += 2;
            }
            res = min(res, cur);
        }

        return res != 2e9 ? res : -1;
    }
};