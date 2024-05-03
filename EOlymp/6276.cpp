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

    int targetSize, takeLimit;
    cin >> targetSize >> takeLimit;

    vector<int> res(targetSize + 1);
    for (int size = 1; size <= targetSize; size++) {
        for (int take = 1; take <= takeLimit; take++) {
            if (!res[size - take]) {
                res[size] = take;
                break;
            }
        }
    }

    cout << res[targetSize];
}