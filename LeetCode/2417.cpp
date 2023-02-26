class Solution {
    bool check(int n) {
        vector<int> count(2);
        while (n) {
            count[n % 10 % 2]++;
            n /= 10;
        }
        return count[0] == count[1];
    }

public:
    int closestFair(int n) {
        for (int i = 0; i < 1e4; i++)
            if (check(n + i))
                return n + i;

        int digitCount = to_string(n).size() / 2 + 1;
        return stoi("1" + string(digitCount, '0') + string(digitCount - 1, '1'));
    }
};