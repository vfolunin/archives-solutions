class Leaderboard {
    unordered_map<int, int> score;
    set<pair<int, int>> scores;

public:    
    void addScore(int id, int delta) {
        scores.erase({ score[id], id });
        score[id] += delta;
        scores.insert({ score[id], id });
    }
    
    int top(int n) {
        int sum = 0;
        auto it = scores.rbegin();
        for (int i = 0; i < n; i++) {
            sum += it->first;
            it++;
        }
        return sum;
    }
    
    void reset(int id) {
        scores.erase({ score[id], id });
        score[id] = 0;
        scores.insert({ score[id], id });
    }
};