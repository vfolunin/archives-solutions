struct BIT {
    vector<int> f;

    BIT(int size) : f(size) {}

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }
};

class Solution {
public:
    string minInteger(string &s, int swapCount) {
        vector<vector<int>> pos(10);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - '0'].push_back(i);

        vector<int> index(10);

        BIT bit(s.size());
        for (int i = 0; i < s.size(); i++)
            bit.add(i, 1);

        string res;
        for (int i = 0; i < s.size(); i++) {
            for (int digit = 0; 1; digit++) {
                if (index[digit] < pos[digit].size() && bit.sum(pos[digit][index[digit]] - 1) <= swapCount) {
                    swapCount -= bit.sum(pos[digit][index[digit]] - 1);
                    bit.add(pos[digit][index[digit]], -1);
                    index[digit]++;
                    res += '0' + digit;
                    break;
                }
            }
        }
        return res;
    }
};