#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int roads, numbers;
    cin >> roads >> numbers;

    if (!roads && !numbers)
        return 0;

    cout << "Case " << test << ": ";

    int groups = (roads + numbers - 1) / numbers;
    int letters = max(0, groups - 1);

    if (letters <= 26)
        cout << letters << "\n";
    else
        cout << "impossible\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}