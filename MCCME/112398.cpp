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

    int limit;
    cin >> limit;

    string name, species;
    int age, count = 0;
    while (cin >> name >> age >> species) {
        if (age < limit) {
            cout << name << " " << age << " " << species << "\n";
            count++;
        }
    }
    
    cout << count;
}