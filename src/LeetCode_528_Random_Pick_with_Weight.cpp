#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "gtest/gtest.h"

using namespace std;

// 528. Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight/?fbclid=IwAR0hA4bxgCC82RStKGjejubfX59KqTNLjlSzhlUADWDrunkW2MSK_xg8siY
// solution : https://www.youtube.com/watch?v=KAZM4tsH8aI&t=92s
// DO NOT use rand() after C++11 ! : https://leetcode.com/problems/random-pick-with-blacklist/discuss/146356/C++-DO-NOT-use-rand()-after-C++11-!
// Since C++11, STL support discrete distribution : https://leetcode.com/problems/random-pick-with-weight/discuss/229600/c%2B%2B-short-stl-solution

// input [1,3,4,4]
// create weight array [1,4,8,12]
// find random position using binary search

class Solution 
{
private:
    vector<int> weightSums;
    int sum;
public:
    Solution(vector<int> w) {
        srand(time(NULL));

        sum = 0;
        vector<int>::iterator itr;
        for (itr = w.begin(); itr < w.end(); itr++) {
            int weight = *itr;
            sum += weight;
            weightSums.push_back(sum);
        }
    }

    int pickIndex() {
        int random = rand() % sum;
        int l = 0;
        int r = weightSums.size() -1;

        cout << "sum=" << to_string(sum) << endl;
        cout << "random=" << to_string(random) << endl;
        while (l < r) {
            int m = (l+r)/2;
            if (weightSums[m] <= random) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
};

TEST(RandomPickwithWeight, HandlesPositiveInput)
{
    vector<int> input = {3, 14, 1, 7};
    Solution solution(input);
    for (int i = 0; i < 10; i++) {
        cout << to_string(solution.pickIndex()) << endl;
    }
}
