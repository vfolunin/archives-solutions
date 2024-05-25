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

    int targetSize;
    cin >> targetSize;

    vector<int> maxParts(targetSize + 1, -1);
    maxParts[0] = 0;

    for (int i = 0; i < 3; i++) {
        int partSize;
        cin >> partSize;

        for (int size = partSize; size <= targetSize; size++)
            if (maxParts[size - partSize] != -1)
                maxParts[size] = max(maxParts[size], maxParts[size - partSize] + 1);
    }

    cout << maxParts.back();
}