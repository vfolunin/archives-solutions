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

    long long sum = 0;
    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    long long res = 0;
    for (int value : a) {
        res += sum * value;
        sum -= value;
        res += sum * value;
    }

    cout << res;
}