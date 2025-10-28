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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    swap(*max_element(a.begin(), a.end()), a.back());

    cout.precision(2);
    for (double value : a)
        cout << fixed << value << "\n";
}