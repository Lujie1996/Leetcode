//
//  main.cpp
//  489. Robot Room Cleaner
//
//  Created by Jie Lu on 2018/10/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, unordered_map<int,int>> cleaned;
    // a -> b -> c: if cell [a][b] has been cleaned
public:
    void dfs(Robot &robot, int i, int j, int &cur_dir) {
        if (cleaned[i][j] == 1) {
            return;
        }
        
        cleaned[i][j] = 1;
        robot.clean();
        
        for (int n = 0; n < 4; ++n) {
            if (robot.move()) {
                int x = i, y = j;
                switch(cur_dir) {
                    case 0:
                        x = i - 1;
                        break;
                    case 90:
                        y = j + 1;
                        break;
                    case 180:
                        x = i + 1;
                        break;
                    case 270:
                        y = j - 1;
                        break;
                    default:
                        break;
                }
                dfs(robot, x, y, cur_dir);
                
                // robot walks back from ajacent position to original position
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            // iteratively tries all four directions
            robot.turnRight();
            cur_dir += 90;
            cur_dir %= 360;
        }
    }
    
    void cleanRoom(Robot& robot) {
        int cur_dir = 0;
        dfs(robot, 0, 0, cur_dir);//0->up, 90->right, 180->down, 270->left
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
