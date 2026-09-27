class Solution {
public:
    long long validSubarrays(vector<int> &a, int limit) {
        vector<int> peakPos = { -1 };
        for (int i = 1; i + 1 < a.size(); i++)
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                peakPos.push_back(i);
        peakPos.push_back(a.size());

        long long res = 0;
        for (int i = 1; i + 1 < peakPos.size(); i++) {
            long long l = min(peakPos[i] - peakPos[i - 1], limit + 1);
            long long r = min(peakPos[i + 1] - peakPos[i], limit + 1);
            res += l * r;
        }
        return res;
    }
};