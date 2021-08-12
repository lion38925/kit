class Solution {
private:
    unordered_map<int, vector<int>> obstaclesMap; //Holds all obstacle points
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (auto item : obstacles) {
            obstaclesMap[item[0]].push_back(item[1]);
        }
        
        char direction = 'N'; // Initial direction
        int x = 0, y = 0; // Grid
        int op = 0; // Output (Holds the maximum of all the distances)
        for (int i = 0; i < commands.size(); i++) {
            // To change directions
            if (commands[i] == -1) { // Turn right
                if (direction == 'N') direction = 'E';
                else if (direction == 'S') direction = 'W';
                else if (direction == 'E') direction = 'S';
                else if (direction == 'W') direction = 'N';
                continue;
            }
            else if (commands[i] == -2) { // Turn left
                if (direction == 'N') direction = 'W';
                else if (direction == 'S') direction = 'E';
                else if (direction == 'E') direction = 'N';
                else if (direction == 'W') direction = 'S';
                continue;
            }
            else { // To move the robot
                int a;
                switch(direction) {
                    case 'N':
                        a = commands[i];
                        // Move only if not an obstacle
                        while (a > 0 && !isObstacle(x, y + 1)) {
                            a--; y++;
                        }
                        break;
                    case 'S':
                        a = commands[i];
                        // Move only if not an obstacle
                        while (a > 0 && !isObstacle(x, y - 1)) {
                            a--; y--;
                        }
                        break;
                    case 'E':
                        a = commands[i];
                        // Move only if not an obstacle
                        while (a > 0 && !isObstacle(x + 1, y)) {
                            a--; x++;
                        }
                        break;
                    case 'W':
                        a = commands[i];
                        // Move only if not an obstacle
                        while (a > 0 && !isObstacle(x - 1, y)) {
                            a--; x--;
                        }
                        break;
                }
            }
            // The output is not the final distance from origin
            // but the maximum distance from the origin while making different stops
            int dis = (pow(abs(y - 0), 2) + pow(abs(x - 0), 2));
            op = std::max(op, dis);
        }
        
        return op;
    }
    
    // To only move is not an obstacle
    bool isObstacle(int x, int y) {
        auto it = obstaclesMap.find(x);
        if (it == obstaclesMap.end())
            return false;
        if (std::find(it->second.begin(), it->second.end(), y) == it->second.end())
            return false;
        return true;
    }
};