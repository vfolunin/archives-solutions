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

    vector<long long> a(size);
    long long product = 1;
    for (long long &value : a) {
        cin >> value;
        product *= value;
    }

    long long res = 0;
    for (long long value : a)
        res += 2 * (product / value);

    cout << res;
}