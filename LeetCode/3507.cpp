class Solution {
public:
    int minimumPairRemoval(vector<int> &a) {
        int res = 0;

        while (!is_sorted(a.begin(), a.end())) {
            int minSum = 1e9, minIndex;
            for (int i = 0; i + 1 < a.size(); i++) {
                if (minSum > a[i] + a[i + 1]) {
                    minSum = a[i] + a[i + 1];
                    minIndex = i;
                }
            }

            a[minIndex] += a[minIndex + 1];
            a.erase(a.begin() + minIndex + 1);
            res++;
        }
        
        return res;
    }
};