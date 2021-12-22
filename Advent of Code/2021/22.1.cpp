#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct Operation {
    char type[5];
    int x1, x2, y1, y2, z1, z2;

    bool covers(int x, int y, int z) {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2 && z1 <= z && z <= z2;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Operation> ops;

    while (1) {
        Operation op;
        if (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d",
            op.type, &op.x1, &op.x2, &op.y1, &op.y2, &op.z1, &op.z2) == EOF)
            break;
        ops.push_back(op);
    }

    int res = 0;
    for (int x = -50; x <= 50; x++) {
        for (int y = -50; y <= 50; y++) {
            for (int z = -50; z <= 50; z++) {
                int state = 0;
                for (Operation &op : ops)
                    if (op.covers(x, y, z))
                        state = op.type[1] == 'n';
                res += state;
            }
        }
    }

    printf("%d", res);
}