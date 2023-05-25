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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    swap(a[0], a[1]);
    swap(a[2], a[a.size() - 1]);
    swap(a[0], a[4]);

    for (int value : a)
        cout << value << " ";
}