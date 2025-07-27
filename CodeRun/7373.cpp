#include <vector>
#include <unordered_map>
using namespace std;

int solve(int size, const vector<long long> &a) {
    unordered_map<long long, int> count;
    int res = 0;

    for (int l = 0, r = 0; r < a.size(); r++) {
        count[a[r]]++;
        while (count.size() > 2) {
            if (!--count[a[l]])
                count.erase(a[l]);
            l++;
        }
        if (count.size() == 2)
            res = max(res, r - l + 1);
    }

    return res;
}