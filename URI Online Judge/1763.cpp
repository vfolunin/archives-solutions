#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<string, string> getMap() {
    map<string, string> m;
    m["brasil"] = "Feliz Natal!";
    m["alemanha"] = "Frohliche Weihnachten!";
    m["austria"] = "Frohe Weihnacht!";
    m["coreia"] = "Chuk Sung Tan!";
    m["espanha"] = "Feliz Navidad!";
    m["grecia"] = "Kala Christougena!";
    m["estados-unidos"] = "Merry Christmas!";
    m["inglaterra"] = "Merry Christmas!";
    m["australia"] = "Merry Christmas!";
    m["portugal"] = "Feliz Natal!";
    m["suecia"] = "God Jul!";
    m["turquia"] = "Mutlu Noeller";
    m["argentina"] = "Feliz Navidad!";
    m["chile"] = "Feliz Navidad!";
    m["mexico"] = "Feliz Navidad!";
    m["antardida"] = "Merry Christmas!";
    m["canada"] = "Merry Christmas!";
    m["irlanda"] = "Nollaig Shona Dhuit!";
    m["belgica"] = "Zalig Kerstfeest!";
    m["italia"] = "Buon Natale!";
    m["libia"] = "Buon Natale!";
    m["siria"] = "Milad Mubarak!";
    m["marrocos"] = "Milad Mubarak!";
    m["japao"] = "Merii Kurisumasu!";
    return m;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    static map<string, string> m = getMap();

    if (m.count(s))
        cout << m[s] << "\n";
    else
        cout << "--- NOT FOUND ---\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}