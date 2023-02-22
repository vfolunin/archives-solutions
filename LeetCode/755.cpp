class Solution {
public:
    vector<int> pourWater(vector<int> &a, int volume, int from) {
        for (int i = 0; i < volume; i++) {
            int bestTo = from;

            for (int d : { -1, 1 }) {
                for (int step = 1; 1; step++) {
                    int to = from + d * step;
                    if (to < 0 || to >= a.size() || a[to] > a[bestTo])
                        break;

                    if (a[bestTo] > a[to])
                        bestTo = to;
                }

                if (bestTo != from)
                    break;
            }

            a[bestTo]++;
        }
        
        return a;
    }
};