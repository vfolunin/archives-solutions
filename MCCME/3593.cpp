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

    vector<long long> count(7), count2(70);
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);

        count[a]++;
        if (a < b)
            count[b]++;
        count2[a * 10 + b]++;
    }

    long long res = 0;
    for (long long count : count)
        res += count * (count - 1) / 2;
    for (int i = 0; i < count2.size(); i++)
        if (i / 10 != i % 10)
            res -= count2[i] * (count2[i] - 1) / 2;

    cout << res;
}