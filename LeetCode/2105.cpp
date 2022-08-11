class Solution {
    void waterPlant(int &volume, int plantVolume, int capacity, int &refill) {
        if (volume >= plantVolume) {
            volume -= plantVolume;
        } else {
            refill++;
            volume = capacity - plantVolume;
        }
    }
    
public:
    int minimumRefill(vector<int> &plantVolume, int aCapacity, int bCapacity) {
        int res = 0, aVolume = aCapacity, bVolume = bCapacity;
        for (int ai = 0, bi = plantVolume.size() - 1; ai <= bi; ai++, bi--) {
            if (ai < bi) {
                waterPlant(aVolume, plantVolume[ai], aCapacity, res);
                waterPlant(bVolume, plantVolume[bi], bCapacity, res);
            } else if (aVolume >= bVolume) {
                waterPlant(aVolume, plantVolume[ai], aCapacity, res);
            } else {
                waterPlant(bVolume, plantVolume[bi], bCapacity, res);
            }
        }
        return res;
    }
};