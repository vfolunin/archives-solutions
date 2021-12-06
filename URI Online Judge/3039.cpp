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

    int n;
    cin >> n;

    int m = 0, f = 0;
    for (int i = 0; i < n; i++) {
        string name, gender;
        cin >> name >> gender;
        m += gender == "M";
        f += gender == "F";
    }

    cout << m << " carrinhos\n";
    cout << f << " bonecas\n";
}