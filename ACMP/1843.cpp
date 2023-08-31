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

    double n;
    cin >> n;

    vector<double> cashbacks = { n * 3 / 100, floor(n / 50) * 2, floor(n / 100) * 5 };
    vector<string> names = { "Vendel Bank", "Beta Bank", "Darkoff Bank" };

    cout << names[max_element(cashbacks.begin(), cashbacks.end()) - cashbacks.begin()];
}