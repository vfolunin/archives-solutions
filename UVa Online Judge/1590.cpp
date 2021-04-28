#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long readIp() {
    long long a, b, c, d;
    scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

void writeIp(long long ip) {
    printf("%lld.%lld.%lld.%lld\n", (ip >> 24) & 255, (ip >> 16) & 255, (ip >> 8) & 255, ip & 255);
}

bool solve() {
    int ipCount;
    if (scanf("%d", &ipCount) == EOF)
        return 0;

    long long conj = -1, disj = 0, ip;
    for (int i = 0; i < ipCount; i++) {
        ip = readIp();
        conj &= ip;
        disj |= ip;
    }

    int bit = 31;
    while (bit >= 0 && (conj & (1LL << bit)) == (disj & (1LL << bit)))
        bit--;
    long long mask = ~((1LL << (bit + 1)) - 1);

    writeIp(ip & mask);
    writeIp(mask);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}