class Solution {
public:
    int getMaxRepetitions(string &a, int an, string &b, int bn) {
        vector<int> nextBi(an + 1);
        vector<int> bCyclesInACycles(an + 1);
        int bi = 0, bCycles = 0;
        
        for (int aCycles = 1; aCycles <= an; aCycles++) {
            for (int ai = 0; ai < a.size(); ai++) {
                if (a[ai] == b[bi]) {
                    bi = (bi + 1) % b.size();
                    bCycles += !bi;
                }
            }
            
            nextBi[aCycles] = bi;
            bCyclesInACycles[aCycles] = bCycles;
            
            for (int ac = 0; ac < aCycles; ac++) {
                if (nextBi[ac] == bi) {
                    int bc = bCyclesInACycles[ac];
                    bc += (an - ac) / (aCycles - ac) * (bCyclesInACycles[aCycles] - bCyclesInACycles[ac]);
                    bc += bCyclesInACycles[ac + (an - ac) % (aCycles - ac)] - bCyclesInACycles[ac];
                    return bc / bn;
                }
            }
        }
        
        return bCyclesInACycles[an] / bn;
    }
};