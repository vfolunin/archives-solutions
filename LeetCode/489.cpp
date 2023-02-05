class Solution {
    void rec(Robot &robot, int y, int x, int d, set<pair<int, int>> &visited) {
        visited.insert({ y, x });
        robot.clean();
        
        static const vector<int> DY = { -1, 0, 1, 0 };
        static const vector<int> DX = { 0, 1, 0, -1 };

        for (int i = 0; i < DY.size(); i++) {
            int ty = y + DY[d];
            int tx = x + DX[d];

            if (!visited.count({ ty, tx }) && robot.move())
                rec(robot, ty, tx, d, visited);
            
            d = (d + 1) % 4;
            robot.turnRight();
        }

        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

public:
    void cleanRoom(Robot &robot) {
        set<pair<int, int>> visited;
        rec(robot, 0, 0, 0, visited);
    }
};