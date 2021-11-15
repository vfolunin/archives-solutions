#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Country {
    string name;
    vector<int> medals;

    Country() : medals(3) {}

    bool operator < (const Country &that) const {
        if (medals != that.medals)
            return medals > that.medals;
        return name < that.name;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int countryCount;
    cin >> countryCount;

    vector<Country> countries(countryCount);
    for (auto &[name, m] : countries)
        cin >> name >> m[0] >> m[1] >> m[2];
    sort(countries.begin(), countries.end());

    for (auto &[name, m] : countries)
        cout << name << " " << m[0] << " " << m[1] << " " << m[2] << "\n";
}