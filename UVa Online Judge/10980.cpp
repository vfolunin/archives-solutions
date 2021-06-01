#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    int whole, frac;
    char dot;
    cin >> whole >> dot >> frac;
    return whole * 100 + frac;
}

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

bool solve(int test) {
    int unitPrice = read();
    int priceCount;
    if (!(cin >> priceCount))
        return 0;

    vector<pair<int, int>> prices(priceCount);
    for (auto &[count, price] : prices) {
        cin >> count;
        price = read();
    }

    vector<int> minPrice(201);
    minPrice[0] = 0;
    for (int items = 1; items < minPrice.size(); items++)
        minPrice[items] = minPrice[items - 1] + unitPrice;

    for (auto &[count, price] : prices)
        for (int items = count; items < minPrice.size(); items++)
            minPrice[items] = min(minPrice[items], minPrice[items - count] + price);
    
    cin.ignore();
    vector<int> queries = readInts();

    cout << "Case " << test << ":\n";
    for (int query : queries) {
        int res = *min_element(minPrice.begin() + query, minPrice.end());
        cout << "Buy " << query << " for $" << res / 100 << "." << setw(2) << setfill('0') << res % 100 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}