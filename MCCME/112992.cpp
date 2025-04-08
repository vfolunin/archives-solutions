#include <iostream>
#include <iomanip>
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

    vector<double> a(size);
    int w = 0;

    for (double &value : a) {
        cin >> value;
        w = max<int>(w, log10(value) + 1);
    }

    cout.precision(2);
    for (double value : a)
        cout << setw(w + 3) << fixed << value << "\n";
}