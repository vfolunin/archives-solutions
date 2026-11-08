#include <iostream>
#include <algorithm>
#include <cmath>
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

    sort(a.begin(), a.end());

    vector<int> b;
    for (int i = 0; i < size; i += 2)
        b.push_back(a[i]);
    for (int i = a.size() - 1 - a.size() % 2; i > 0; i -= 2)
        b.push_back(a[i]);

    double area = 0;
    for (int i = 0; i < b.size(); i++)
        area += b[i] * b[(i + 1) % b.size()] * 0.5 * sin(acos(-1) * 2 / size);

    cout.precision(3);
    cout << fixed << area << "\n";
}