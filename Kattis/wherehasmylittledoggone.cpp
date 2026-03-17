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

    double a, b;
    int size;
    cin >> a >> b >> size;

    bool found = 0;
    for (int i = 0; i < size; i++) {
        string name;
        double abl, abr, al, ar;
        cin >> name >> abl >> abr >> al >> ar;

        if (abl <= a / b && a / b <= abr && al <= a && a <= ar) {
            cout << name << "\n";
            found = 1;
        }
    }

    if (!found)
        cout << "Mutt";
}