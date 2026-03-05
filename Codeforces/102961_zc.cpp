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

    vector<int> seen(size);
    seen[0]++;
    long long sum = 0, res = 0;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;

        sum = ((sum + x) % size + size) % size;
        res += seen[sum];
        seen[sum]++;
    }

    cout << res;
}