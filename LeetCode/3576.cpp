class Solution {
public:
    bool canMakeEqual(vector<int> &a, int limit) {
        for (int value : { -1, 1 }) {
            vector<int> cur = a;

            int ops = 0;
            for (int i = 0; i + 1 < cur.size() && ops <= limit; i++) {
                if (cur[i] != value) {
                    ops++;
                    cur[i + 1] *= -1;
                }
            }

            if (cur.back() == value && ops <= limit)
                return 1;
        }
        
        return 0;
    }
};