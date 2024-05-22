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

    int size;
    cin >> size;

    vector<int> weights(size);
    for (int &weight : weights)
        cin >> weight;

    sort(weights.begin(), weights.end());

    vector<long long> minWeight(weights.size() + 1, 1e18);
    minWeight[0] = 0;
    int maxHeight = 0;

    for (int weight : weights) {
        for (int height = maxHeight; height >= 0; height--)
            if (weight >= minWeight[height] * 2 && minWeight[height + 1] > weight + minWeight[height])
                minWeight[height + 1] = weight + minWeight[height];
        while (maxHeight < weights.size() && minWeight[maxHeight + 1] < 1e18)
            maxHeight++;
    }

    cout << maxHeight;
}