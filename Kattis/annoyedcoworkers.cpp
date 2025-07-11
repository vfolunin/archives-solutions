#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<pair<long long, long long>> pairs, int questionCount, long long limit) {
    long long answerCount = 0;
    for (auto &[value, delta] : pairs) {
        if (value > limit)
            return 0;
        answerCount += (limit - value) / delta;
    }
    return answerCount >= questionCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int questionCount, pairCount;
    cin >> questionCount >> pairCount;

    vector<pair<long long, long long>> pairs(pairCount);
    for (auto &[value, delta] : pairs)
        cin >> value >> delta;

    long long l = 0, r = 1;
    while (!can(pairs, questionCount, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(pairs, questionCount, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}