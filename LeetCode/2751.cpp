struct Robot {
    int index, pos, hp;
    char dir;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &pos, vector<int> &hp, string &dir) {
        vector<Robot> robots(pos.size());
        for (int i = 0; i < robots.size(); i++) {
            robots[i].index = i;
            robots[i].pos = pos[i];
            robots[i].hp = hp[i];
            robots[i].dir = dir[i];
        }
        sort(robots.begin(), robots.end(), [](auto &a, auto &b) { return a.pos < b.pos; });
        
        vector<Robot> right, survived;
        
        for (int i = 0; i < robots.size(); i++) {
            if (robots[i].dir == 'R') {
                right.push_back(robots[i]);
            } else {
                bool destroyed = 0;
                while (!right.empty()) {
                    if (right.back().hp > robots[i].hp) {
                        right.back().hp--;
                        destroyed = 1;
                        break;
                    } else if (right.back().hp == robots[i].hp) {
                        right.pop_back();
                        destroyed = 1;
                        break;
                    } else {
                        right.pop_back();
                        robots[i].hp--;
                    }
                }
                if (!destroyed)
                    survived.push_back(robots[i]);
            }
        }
        
        survived.insert(survived.end(), right.begin(), right.end());
        sort(survived.begin(), survived.end(), [](auto &a, auto &b) { return a.index < b.index; });
        
        vector<int> res;
        for (auto &[index, pos, hp, dir] : survived)
            res.push_back(hp);
        return res;
    }
};