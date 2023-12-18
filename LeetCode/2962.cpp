class Solution {
public:
    long long countSubarrays(vector<int> &a, int threshold) {
        int maxValue = *max_element(a.begin(), a.end());
        int maxValueCount = 0;
        long long res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            maxValueCount += a[r] == maxValue;

            while (maxValueCount >= threshold) {
                maxValueCount -= a[l] == maxValue;
                l++;
            }

            res += l;
        }

        return res;
    }
};