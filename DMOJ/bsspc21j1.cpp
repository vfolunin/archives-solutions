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

    int a, b;
    cin >> a >> b;

    if ((a + 2) * 3 + 16 <= b)
        cout << "Yes it fits!";
    else
        cout << "No, it's too small :(";
}