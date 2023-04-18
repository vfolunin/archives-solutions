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

    double l = 30, r = 4000, cur;
    cin >> cur;

    for (int i = 1; i < size; i++) {
        double prev = cur;
        string verdict;
        cin >> cur >> verdict;

        if (verdict == "closer") {
            if (prev < cur)
                l = max(l, (prev + cur) / 2);
            else
                r = min(r, (prev + cur) / 2);
        } else {
            if (prev < cur)
                r = min(r, (prev + cur) / 2);
            else
                l = max(l, (prev + cur) / 2);
        }
    }

    cout << fixed << l << " " << r;
}