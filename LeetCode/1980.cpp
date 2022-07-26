class Solution {
public:
    string findDifferentBinaryString(vector<string> &a) {
        string res(a.size(), ' ');
        for (int i = 0; i < res.size(); i++)
            res[i] = a[i][i] ^ 1;
        return res;
    }
};