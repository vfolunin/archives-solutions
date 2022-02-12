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

    int b, br, bs, a, as;
    cin >> b >> br >> bs >> a >> as;

    int amount = (br - b) * bs;
    int years = (amount + as) / as;

    cout << a + years;
}