#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int sum;
    cin >> sum;

    if (!sum)
        return 0;

    cout << "Teste " << test << "\n";

    for (int nominal : {50, 10, 5}) {
        cout << sum / nominal << " ";
        sum %= nominal;
    }

    cout << sum << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}