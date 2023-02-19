class SnakeGame {
    int height, width;

    set<pair<int, int>> snakeCells = { { 0, 0 } };
    deque<pair<int, int>> snake = { { 0, 0 } };
    
    vector<pair<int, int>> food;
    int fi = 0;

public:
    SnakeGame(int width, int height, vector<vector<int>> &foodCells) : height(height), width(width) {
        for (vector<int> &cell : foodCells)
            food.push_back({ cell[0], cell[1] });
    }
    
    int move(const string &d) {
        static const unordered_map<string, pair<int, int>> OFFSETS = {
            { "U", { -1, 0 } }, { "L", { 0, -1 } }, { "D", { 1, 0 } }, { "R", { 0, 1 } }
        };

        auto [y, x] = snake.front();
        auto [dy, dx] = OFFSETS.at(d);
        int ty = y + dy, tx = x + dx;

        if (ty < 0 || ty >= height || tx < 0 || tx >= width)
            return -1;
        
        if (fi < food.size() && make_pair(ty, tx) == food[fi]) {
            fi++;
        } else {
            snakeCells.erase(snake.back());
            snake.pop_back();
        }

        if (snakeCells.count({ ty, tx }))
            return -1;
        
        snakeCells.insert({ ty, tx });
        snake.push_front({ ty, tx });
        return fi;
    }
};