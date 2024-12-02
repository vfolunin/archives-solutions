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

    string a, b;
    cin >> a >> a >> b;

    if (b.find(a) != -1)
        cout << "Unnar fann hana!";
    else
        cout << "Unnar fann hana ekki!";
}