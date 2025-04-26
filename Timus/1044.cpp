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
    size /= 2;

    int limit = 1;
    for (int i = 0; i < size; i++)
        limit *= 10;

    vector<int> count(size * 9 + 1);
    for (int i = 0; i < limit; i++) {
        int value = i, sum = 0;
        for (int j = 0; j < size; j++) {
            sum += value % 10;
            value /= 10;
        }
        count[sum]++;
    }

    long long res = 0;
    for (int count : count)
        res += count * count;

    cout << res;
}