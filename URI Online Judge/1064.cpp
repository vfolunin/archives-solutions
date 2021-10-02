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

    double sum = 0;
    int count = 0;

    for (int i = 0; i < 6; i++) {
        double x;
        cin >> x;

        if (x > 0) {
            sum += x;
            count++;
        }
    }

    cout << count << " valores positivos\n";
    cout.precision(1);
    cout << fixed << sum / count << "\n";
}