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

    for (int i = 0; i + 1 < a.size(); i++)
        if (a[i] < 0 && a[i + 1] < 0 || a[i] > 0 && a[i + 1] > 0)
            cout << a[i] << " " << a[i + 1] << "\n";
}