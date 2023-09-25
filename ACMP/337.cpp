#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> hasStep(51);
    for (int i = 0; i < queryCount; i++) {
        int step;
        cin >> step;
        hasStep[step] ^= 1;
    }

    map<int, int> stepFactor;
    for (int step = 1; step < hasStep.size(); step++) {
        if (hasStep[step]) {
            map<int, int> stepDelta = { { step, 1 } };

            for (auto &[prevStep, prevFactor] : stepFactor) {
                long long commonStep = lcm<long long>(prevStep, step);
                if (commonStep <= size)
                    stepDelta[commonStep] -= 2 * prevFactor;
            }

            for (auto &[step, delta] : stepDelta)
                stepFactor[step] += delta;
        }
    }

    int res = 0;
    for (auto &[step, factor] : stepFactor)
        res += size / step * factor;

    cout << res;
}