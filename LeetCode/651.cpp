class Solution {
public:
    int maxA(int opCount) {
        vector<int> res(opCount + 1);
        for (int ops = 0; ops <= opCount; ops++) {
            res[ops] = ops;
            for (int pastes = 1; 2 + pastes < ops; pastes++)
                res[ops] = max(res[ops], res[ops - 2 - pastes] * (1 + pastes));
        }
        return res[opCount];
    }
};