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

    long long index, a, b, c;
    cin >> index >> a >> b >> c;

    index--;
    index %= a + b + c + b + a;

    if (index < a || index >= a + b + c + b)
        cout << "G";
    else if (index < a + b || index >= a + b + c)
        cout << "Y";
    else
        cout << "R";
}