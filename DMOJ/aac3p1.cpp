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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b)
        cout << (c < d ? "Go to the department store\n" : "Go to the grocery store\n");
    else
        cout << (c < d ? "Go to the pharmacy\n" : "Stay home\n");
}