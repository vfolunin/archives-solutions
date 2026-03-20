#include <algorithm>
#include <vector>
using namespace std;

long long solution(int size, int queryCount, vector<long long> &a, vector<pair<int, int>> &queries) {
    vector<int> b(a.size());
    for (auto &[l, r] : queries) {
        b[l - 1]++;
        if (r < b.size())
            b[r]--;
    }
    for (int i = 1; i < b.size(); i++)
        b[i] += b[i - 1];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    return res;
}
