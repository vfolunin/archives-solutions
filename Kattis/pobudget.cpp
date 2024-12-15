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

    int sum = 0;
    for (int i = 0; i < size; i++) {
        string s;
        int delta;
        cin >> s >> delta;
        sum += delta;
    }

    if (sum > 0)
        cout << "Usch, vinst";
    else if (sum == 0)
        cout << "Lagom";
    else
        cout << "Nekad";
}