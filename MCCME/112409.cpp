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

    vector<string> a(size);
    for (string &value : a)
        cin >> value >> value;

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        cout << i + 1 << ". " << a[i] << "\n";
}