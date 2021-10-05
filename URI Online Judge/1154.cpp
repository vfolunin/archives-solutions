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

    double sum = 0, cnt = 0;

    while (1) {
        double x;
        cin >> x;

        if (x < 0)
            break;

        sum += x;
        cnt++;
    }

    cout.precision(2);
    cout << fixed << sum / cnt << "\n";
}