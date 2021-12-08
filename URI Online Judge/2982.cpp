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

    vector<int> sum(2);
    for (int i = 0; i < n; i++) {
        char type;
        int value;
        cin >> type >> value;
        sum[type == 'V'] += value;
    }

    if (sum[0] <= sum[1])
        cout << "A greve vai parar.\n";
    else
        cout << "NAO VAI TER CORTE, VAI TER LUTA!\n";
}