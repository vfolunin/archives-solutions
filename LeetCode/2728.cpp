class Solution {
public:
    int houseCount(Street *street, int limit) {
        for (int i = 0; i < limit; i++) {
            if (street->isDoorOpen())
                street->closeDoor();
            street->moveRight();
        }

        street->openDoor();
        street->moveRight();

        int res = 1;
        while (!street->isDoorOpen()) {
            street->moveRight();
            res++;
        }
        return res;
    }
};