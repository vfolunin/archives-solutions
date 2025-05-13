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

    vector<double> p(size);
    double totalP = 0;

    for (double &p : p) {
        double a, b;
        cin >> a >> b;

        p = a * b;
        totalP += p;
    }

    cout.precision(10);
    for (double &p : p)
        cout << fixed << p / totalP << "\n";
}