#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int riverCount, distance;
    cin >> riverCount >> distance;

    if (!riverCount && !distance)
        return 0;

    double res = distance;
    for (int i = 0; i < riverCount; i++) {
        double width, speed;
        cin >> width >> width >> speed;
        res -= width;
        res += width * 2 / speed;
    }

    cout.precision(3);
    cout << "Case " << test << ": " << fixed << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}