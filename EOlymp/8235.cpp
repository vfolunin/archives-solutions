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

    int size, brokenCount;
    cin >> size >> brokenCount;

    vector<int> broken(size + 1);
    for (int i = 0; i < brokenCount; i++) {
        int index;
        cin >> index;
        broken[index] = 1;
    }

    vector<long long> ways(size + 1);
    ways[0] = 1;

    for (int i = 1; i < ways.size(); i++) {
        if (broken[i])
            continue;

        for (int step = 1; step <= 3; step++)
            if (0 <= i - step)
                ways[i] += ways[i - step];
    }

    cout << (ways.back() ? ways.back() : -1);
}