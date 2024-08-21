class Solution {
    vector<int> getPowerOfTenMod(int targetSize, int divisor) {
        vector<int> powerOfTenMod(targetSize + 1);
        powerOfTenMod[0] = 1 % divisor;
        for (int size = 1; size <= targetSize; size++)
            powerOfTenMod[size] = powerOfTenMod[size - 1] * 10 % divisor;
        return powerOfTenMod;
    }

    int rec(int i, int mod, int targetSize, int divisor, const vector<int> &powerOfTenMod, vector<vector<int>> &nextDigit, vector<vector<int>> &nextMod) {
        int &res = nextDigit[i][mod];
        if (res != -2)
            return res;

        if (i == (targetSize + 1) / 2)
            return res = mod ? -1 : 0;

        for (int digit = 9; digit >= 0; digit--) {
            int nMod = (mod + digit * powerOfTenMod[targetSize - 1 - i] + (i < targetSize / 2 ? digit * powerOfTenMod[i] : 0)) % divisor;
            if (rec(i + 1, nMod, targetSize, divisor, powerOfTenMod, nextDigit, nextMod) != -1) {
                nextMod[i][mod] = nMod;
                return res = digit;
            }
        }

        return res = -1;
    }

public:
    string largestPalindrome(int targetSize, int divisor) {
        vector<vector<int>> nextDigit(targetSize + 1, vector<int>(divisor, -2));
        vector<vector<int>> nextMod(targetSize + 1, vector<int>(divisor, -1));
        rec(0, 0, targetSize, divisor, getPowerOfTenMod(targetSize, divisor), nextDigit, nextMod);

        string res;
        for (int i = 0, mod = 0; i < (targetSize + 1) / 2; mod = nextMod[i][mod], i++)
            res += string(1, nextDigit[i][mod] + '0');
        res += string(res.rbegin() + targetSize % 2, res.rend());
        return res;
    }
};