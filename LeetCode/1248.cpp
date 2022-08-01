class Solution {
public:
    int numberOfSubarrays(vector<int> &a, int k) {
        vector<int> oddPos = { -1 };
        for (int i = 0; i < a.size(); i++)
            if (a[i] % 2)
                oddPos.push_back(i);
        oddPos.push_back(a.size());
        
        int res = 0;
        for (int i = k; i + 1 < oddPos.size(); i++) {
            int l = oddPos[i - k + 1] - oddPos[i - k];
            int r = oddPos[i + 1] - oddPos[i];
            res += l * r;
        }
        return res;
    }
};