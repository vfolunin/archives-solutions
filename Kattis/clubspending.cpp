#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, double> sum;
    for (int i = 0; i < size; i++) {
        string id;
        char currency;
        double delta;
        cin >> id >> currency >> delta;

        sum[id] += delta;

        cout.precision(2);
        cout << id << " " << currency << fixed << sum[id] << "\n";
    }
}