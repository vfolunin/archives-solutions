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

    int limit, size;
    cin >> limit >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
        if (i >= 4)
            sum -= a[i - 4];
        if (sum > limit) {
            cout << i;
            return 0;
        }
    }

    cout << size;
}