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

    int personCount, opCount;
    cin >> personCount >> opCount;

    vector<int> account(personCount);
    for (int i = 0; i < opCount; i++) {
        int a, b, value;
        cin >> a >> b >> value;
        account[a - 1] -= value;
        account[b - 1] += value;
    }

    for (int value : account)
        cout << value << " ";
}