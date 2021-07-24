#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int playerCount;
    cin.ignore(8);
    cin >> playerCount;

    vector<double> x(playerCount), y(playerCount), v(playerCount);
    for (int i = 0; i < playerCount; i++)
        cin >> x[i] >> y[i] >> v[i];

    int ballCount;
    cin.ignore(7);
    cin >> ballCount;

    for (int i = 1; i <= ballCount; i++) {
        double a, b, c, d, e, f, g;
        cin >> a >> b >> c >> d >> e >> f >> g;

        double discr = b * b - 4 * a * c;
        double t = ceil((-b - sqrt(discr)) / (2 * a));
        double bx = d * t + e;
        double by = f * t + g;

        cout << "Ball " << i << " was ";
        if (bx < 0 || by < 0) {
            cout << "foul";
        } else {
            bool caught = 0;
            for (int j = 0; !caught && j < playerCount; j++)
                caught |= v[j] * t >= hypot(bx - x[j], by - y[j]);
            cout << (caught ? "caught" : "safe");
        }
        cout.precision(0);
        cout << " at (" << fixed << bx << "," << by << ")\n";
    }
}