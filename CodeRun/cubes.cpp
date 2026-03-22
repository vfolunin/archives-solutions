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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    vector<int> res;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
    cout << "\n";

    res.clear();
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
    cout << "\n";

    res.clear();
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(res));
    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}