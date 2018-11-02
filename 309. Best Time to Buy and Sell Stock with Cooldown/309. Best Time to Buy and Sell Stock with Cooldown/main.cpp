//
//  main.cpp
//  Premium New Playground georgelu  309. Best Time to Buy and Sell Stock with Cooldown
//
//  Created by Jie Lu on 2018/5/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}
int main(int argc, const char * argv[]) {
    int a[] = {6,1,3,2,4,7};
    vector<int> prices(a, a+6);
    cout<<maxProfit(prices)<<endl;
    return 0;
}

