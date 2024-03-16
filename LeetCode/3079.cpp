class Solution {
    int encrypt(int value) {
        string s = to_string(value);
        fill(s.begin(), s.end(), *max_element(s.begin(), s.end()));
        return stoi(s);
    }

public:
    int sumOfEncryptedInt(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res += encrypt(value);
        return res;
    }
};