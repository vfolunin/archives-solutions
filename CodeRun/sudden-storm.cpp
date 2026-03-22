#include <vector>
using namespace std;

vector<long long> solve(int size, int time, vector<long long> &a, vector<long long> &b) {
    long long sumA = 0, sumB = 0;
    vector<vector<int>> end(time + 1);

    for (int i = 0; i < a.size(); i++) {
        sumA += a[i];
        sumB += b[i];
        int endIndex = b[i] ? a[i] / b[i] : 1e9;
        if (endIndex < end.size())
            end[endIndex].push_back(i);
    }

    vector<long long> res(end.size());
    for (int endIndex = 0; endIndex < end.size(); endIndex++) {
        res[endIndex] = sumA;
        for (int i : end[endIndex]) {
            sumA -= a[i] % b[i];
            sumB -= b[i];
        }
        sumA -= sumB;
    }
    return res;
}