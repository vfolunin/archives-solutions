#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetRemainder;
    cin >> size >> targetRemainder;

    vector<int> count(1e6 + 1);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    long long res = 0;
    for (int den = targetRemainder + 1; den < count.size(); den++)
        for (int num = targetRemainder; num < count.size(); num += den)
            if (count[num] && count[den])
                res += 1LL * count[num] * (count[den] - (num == den));

    cout << res;
}