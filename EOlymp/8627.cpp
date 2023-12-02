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

    cout << a[0] << " ";
    for (int i = 1; i + 1 < a.size(); i++)
        cout << a[i - 1] + a[i + 1] << " ";
    cout << a.back();
}