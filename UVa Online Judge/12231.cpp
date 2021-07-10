#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int fileCount, threadCount, bandwidth;
    cin >> fileCount >> threadCount >> bandwidth;

    if (!fileCount && !threadCount && !bandwidth)
        return 0;

    double bytes = 0;
    for (int i = 0; i < fileCount; i++) {
        double size, percent;
        cin >> size >> percent;
        bytes += size * (1 - percent / 100);
    }

    cout.precision(2);
    cout << "Case " << test << ": " << fixed << bytes / bandwidth << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}