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

    if (size == 1) {
        cout << "No";
        return 0;
    }

    vector<int> a(size);
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        if (i)
            sum += a[i] * i;
    }

    cout << "Yes\n" << -sum << " ";
    for (int i = 1; i < a.size(); i++)
        cout << a[0] * i << " ";
}