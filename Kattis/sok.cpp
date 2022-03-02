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

    vector<double> volume(3);
    for (double &v : volume)
        cin >> v;

    vector<double> part(3);
    for (double &p : part)
        cin >> p;

    vector<double> ratio(3);
    for (int i = 0; i < 3; i++)
        ratio[i] = volume[i] / part[i];
    double minRatio = *min_element(ratio.begin(), ratio.end());

    for (int i = 0; i < 3; i++)
        cout << fixed << volume[i] - minRatio * part[i] << " ";
}