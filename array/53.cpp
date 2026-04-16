#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int>& nums)
    {
        int ans         = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum     = 0;
        for (int x : nums)
        {
            pre_sum += x;
            ans         = max(ans, pre_sum - min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum);
        }
        return ans;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> nums, int expected)
{
    Solution sol;
    int      result = sol.maxSubArray(nums);

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  (expected " << expected << ", got " << result << ")";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 53. 最大子数组和 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6);

    // Test 2: 单个正数
    runTest(2, { 1 }, 1);

    // Test 3: 全正数
    runTest(3, { 5, 4, -1, 7, 8 }, 23);

    // Test 4: 单个负数（边界！）
    runTest(4, { -1 }, -1);

    // Test 5: 全部负数（答案是最大的那个负数）
    runTest(5, { -3, -1, -2, -4 }, -1);

    // Test 6: 两个元素
    runTest(6, { 1, 2 }, 3);

    // Test 7: 开头是最大值
    runTest(7, { 10, -5, -5, -5 }, 10);

    // Test 8: 末尾是最大值
    runTest(8, { -5, -5, -5, 10 }, 10);

    // Test 9: 零和负数
    runTest(9, { -1, 0, -2 }, 0);

    return 0;
}