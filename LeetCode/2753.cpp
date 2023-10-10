class Solution {
public:
    int houseCount(Street *street, int limit) {
        int l = -1, r;
        for (int i = 0; l == -1 || i <= r + limit; i++) {
            if (street->isDoorOpen()) {
                if (l == -1)
                    l = i;
                r = i;

                if (l != r)
                    street->closeDoor();
            }
            street->moveRight();
        }
        return r - l;
    }
};