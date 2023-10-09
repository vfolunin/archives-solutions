class Solution {
public:
    int minArrayLength(vector<int> &a, int limit) {
        if (count(a.begin(), a.end(), 0))
            return 1;
        
        int to = 0;
        for (int from = 0; from < a.size(); from++) {
            a[to] = a[from];
            to += !from || a[from - 1] != 1 || a[from] != 1;
        }
        a.erase(a.begin() + to, a.end());
        
        vector<int> res(a.size() + 1);

        for (int size = 1; size <= a.size(); size++) {
            res[size] = size;
            long long product = 1;

            for (int partSize = 1; partSize <= size; partSize++) {
                if (product * a[size - partSize] <= limit) {
                    product *= a[size - partSize];
                    res[size] = min(res[size], res[size - partSize] + 1);
                } else {
                    break;
                }
            }
        }

        return res[a.size()];
    }
};