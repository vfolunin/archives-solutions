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

    int ad, ar, av;
    int bd, br, bv;
    string text;

    cin >> ad >> ar >> av;
    cin >> bd >> br >> bv;
    cin.ignore();
    getline(cin, text);

    int at = ad * 2 + ar + av * text.size();
    int bt = bd * 2 + br + bv * text.size();

    if (at < bt)
        cout << "Matheus\n";
    else if (at == bt)
        cout << "Empate\n";
    else
        cout << "Vinicius\n";
}