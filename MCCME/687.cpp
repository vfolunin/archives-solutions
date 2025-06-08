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

    int maxSize, targetSum;
    cin >> maxSize >> targetSum;

    int res = 0;
    for (int size = 0; size <= maxSize; size++) {
        for (int pos = 0, neg = size; pos <= size; pos++, neg--) {
            if (pos * (pos - 1) / 2 + neg * (neg - 1) / 2 - pos * neg == targetSum) {
                res++;
                break;
            }
        }
    }

    cout << res;
}