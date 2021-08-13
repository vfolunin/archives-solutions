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

    map<string, string> locName;
    map<string, double> locPrice;

    while (1) {
        char locBuf[100];
        scanf("%s", locBuf);
        string loc(locBuf);

        if (loc == "000000")
            break;

        char nameBuf[100];
        int price;
        scanf(" %[^$]$%d", nameBuf, &price);

        locName[loc] = nameBuf;
        locPrice[locBuf] = price / 100.0;
    }

    while (1) {
        char dialBuf[100];
        int time;
        scanf("%s%d", dialBuf, &time);
        string dial(dialBuf);

        if (dial == "#")
            break;

        string resName = "Local", resUser = dial;
        double resPrice = 0;

        for (auto &[loc, name] : locName) {
            if (loc.size() < dial.size() && dial.substr(0, loc.size()) == loc) {
                string user = dial.substr(loc.size());
                if (dial[0] == '0' && dial[1] == '0' && 3 <= loc.size() && loc.size() <= 5 && 4 <= user.size() && user.size() <= 10 ||
                    dial[0] == '0' && dial[1] != '0' && 2 <= loc.size() && loc.size() <= 6 && 4 <= user.size() && user.size() <= 7) {
                    resName = name;
                    resUser = user;
                    resPrice = locPrice[loc];
                }
            }
        }

        if (dial[0] != '0' || resName != "Local")
            printf("%-16s%-25s%10s%5d%6.2lf%7.2lf\n", dial.c_str(), resName.c_str(), resUser.c_str(), time, resPrice, time * resPrice);
        else
            printf("%-16s%-35s%5d%13.2lf\n", dial.c_str(), "Unknown", time, -1.0);
    }
}