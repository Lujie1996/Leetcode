//
//  main.cpp
//  486. Predict the Winner
//
//  Created by Jie Lu on 2018/8/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 DP
 maxPoint[i][j]: max point which the 'first player' can get when they start the game in the subarray nums[i..j]
 Consider how to get maxPoint[i][j] from subproblems. In the beginning, Player 1 can pick either end of nums[i..j].
 Say Player 1 picks nums[i]: now player 2 is the 'first player' in nums[i+1..j], he will must get maxPoint[i+1][j] (since this is the max score he could possibly get); In the rest of the game, player 1 gets the rest scores, which is sum[i+1][j] - maxPoint[i+1][j]. So, the total score player 1 will get is: nums[i] + (sum[i+1][j] - maxPoint[i+1][j]). The case which player 1 picks nums[j] in the beginning is similar to this case.
 So we have:
    maxPoint[i][j] = max{nums[i] + (sum[i+1][j] - maxPoint[i+1][j]), nums[j] + (sum[i][j-1] - maxPoint[i][j-1])}
 */
bool PredictTheWinner(vector<int>& nums) {
    int n = (int)nums.size();
    vector<vector<int>> maxPoint(n, vector<int>(n, 0)), sum(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        maxPoint[i][i] = sum[i][i] = nums[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum[i][j] = sum[i][j-1] + nums[j];
        }
    }
    for (int len = 1; len < n; len++) {
        for (int start = 0; start + len < n; start++) {
            int i = start, j = start + len;
            maxPoint[i][j] = max(nums[i] + (sum[i+1][j] - maxPoint[i+1][j]), nums[j] + (sum[i][j-1] - maxPoint[i][j-1]));
        }
    }
    return maxPoint[0][n-1] >= sum[0][n-1] - maxPoint[0][n-1];
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,5,233,7};
    if (PredictTheWinner(nums)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
