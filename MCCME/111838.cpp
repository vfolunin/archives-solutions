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

    char a, b;
    cin >> a >> b;

    if (isdigit(a) && isalpha(b) || isalpha(a) && isdigit(b))
        cout << "YES";
    else
        cout << "NO";
}