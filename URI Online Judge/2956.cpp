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

    double a, h;
    cin >> a >> h;

    cout.precision(5);
    cout << "Concluimos que, dado o limite da entrada, a resposta seria:  ";
    cout << "y = f(x) = " << fixed << a * h / 2 << ".\n";
}