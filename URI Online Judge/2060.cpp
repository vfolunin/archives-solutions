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

    int n;
    cin >> n;

    vector<int> multipleCount(4);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int j = 0; j < multipleCount.size(); j++)
            if (x % (j + 2) == 0)
                multipleCount[j]++;
    }

    for (int i = 0; i < multipleCount.size(); i++)
        cout << multipleCount[i] << " Multiplo(s) de " << i + 2 << "\n";
}