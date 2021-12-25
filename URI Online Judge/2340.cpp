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

    int bacteriaCount;
    cin >> bacteriaCount;

    vector<double> bacteries(bacteriaCount);
    for (double &b : bacteries) {
        double n, p;
        cin >> n >> p;
        b = p * log(n);
    }

    cout << max_element(bacteries.begin(), bacteries.end()) - bacteries.begin() << "\n";
}