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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (n < a - b - c)
        cout << "Igor feliz!\n";
    else if (b * 2 > c)
        cout << "Caio, a culpa eh sua!\n";
    else
        cout << "Igor bolado!\n";
}