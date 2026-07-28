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

    int va, vb, vc, vm;
    cin >> va >> vb >> vc >> vm;

    for (int a = va; a <= 2 * va; a++) {
        for (int b = vb; b <= 2 * vb && b < a; b++) {
            for (int c = vc; c <= 2 * vc && c < b; c++) {
                if (vm <= a && 2 * vm < a &&
                    vm <= b && 2 * vm < b &&
                    vm <= c && c <= 2 * vm) {
                    cout << a << "\n" << b << "\n" << c;
                    return 0;
                }
            }
        }
    }

    cout << -1;
}