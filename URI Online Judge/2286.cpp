#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int gameCount;
    string name[2];
    if (!(cin >> gameCount >> name[0] >> name[1]))
        return 0;

    cout << "Teste " << test << "\n";
    
    for (int i = 0; i < gameCount; i++) {
        int a, b;
        cin >> a >> b;
        cout << name[(a + b) % 2] << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}