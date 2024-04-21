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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long sum = 0;
    for (int value : a) {
        if (sum + 1 < value) {
            cout << sum + 1;
            return 0;
        }
        sum += value;
    }

    cout << sum + 1;
}