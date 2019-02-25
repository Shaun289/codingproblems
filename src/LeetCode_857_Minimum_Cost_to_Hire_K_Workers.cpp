#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "gtest/gtest.h"

using namespace std;

// 857. Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/?fbclid=IwAR0V6n69Dp3v4VjAPuq1XO7xAMzsCtwsfXiQ20mdDczK6Ed_V9QOkTlLOaw
// solution : https://github.com/jeongmincha/leetcode/blob/master/minimum-cost-to-hire-k-workers/main.py?fbclid=IwAR0nimP-BJd7b2_ItY0KoWLfc1wSOiJVIOf01aQZO_qcgjb66uxUtD2ahMs

class Solution 
{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        // Get wage per quality
        vector<double> wagePerQ;
        for (int i = 0; i < quality.size(); i++) {
            wagePerQ.push_back(((double)wage[i])/quality[i]);
        }

        // goot way to print vector
        // need to study std::copy
        std::ostringstream oss;
        std::copy(wagePerQ.begin(), wagePerQ.end(), ostream_iterator<double>(oss, ","));
        cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << oss.str() << endl;

        // Sort by wagePerQ
        sort(wagePerQ.begin(), wagePerQ.end());

        oss.str("");
        std::copy(wagePerQ.begin(), wagePerQ.end(), ostream_iterator<double>(oss, ","));
        cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << oss.str() << endl;

    };

};

TEST(MinimumCosttoHireKWorkers, HandlesPositiveInput)
{
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int K = 2;
    Solution solution;

    solution.mincostToHireWorkers(quality, wage, K);
#if 0
    EXPECT_EQ(Solution.mincostToHireWorkers(quality, wage, K),  105.0);

    quality = {3, 1, 10, 10, 1};
    wage = {4, 8, 2, 2, 7};
    K = 3;
    EXPECT_EQ(Solution.mincostToHireWorkers(quality, wage, K),  30.66667);
#endif
}
