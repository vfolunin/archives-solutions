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

    int d1, d2, d3, n1, n2, n3;
    cin >> d1 >> d2 >> d3 >> n1 >> n2 >> n3;

    cout << min({ n1 / d1, n2 / d2, n3 / d3 });
}