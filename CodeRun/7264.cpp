#include <algorithm>
#include <vector>
using namespace std;

int solution(int size, vector<int> &a) {
    sort(a.begin(), a.end());

    int res = size;
    for (int l = 0, r = 0; r < size; r++) {
        while (a[l] + size - 1 < a[r])
            l++;
        res = min<int>(res, size - (r - l + 1));
    }
    return res;
}
