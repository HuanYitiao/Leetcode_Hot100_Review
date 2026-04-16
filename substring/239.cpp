#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // TODO: 你来填这里
        // 提示：单调递减队列（deque存下标）
        // 三步：
        //   1. 入队：新元素进来前，把队尾比它小的都pop掉（它们不可能再是最大值）
        //   2. 出队：队首下标如果已经滑出窗口左边界，pop掉
        //   3. 记录：窗口形成后（i >= k-1），队首就是当前窗口最大值
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> nums, int k, vector<int> expected)
{
    Solution sol;
    auto     result = sol.maxSlidingWindow(nums, k);

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  expected [";
        for (int i = 0; i < expected.size(); i++)
        {
            cout << expected[i] << (i < expected.size() - 1 ? "," : "");
        }
        cout << "], got [";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << (i < result.size() - 1 ? "," : "");
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 239. 滑动窗口最大值 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { 1, 3, -1, -3, 5, 3, 6, 7 }, 3, { 3, 3, 5, 5, 6, 7 });

    // Test 2: 单元素
    runTest(2, { 1 }, 1, { 1 });

    // Test 3: k等于数组长度
    runTest(3, { 1, 2, 3, 4, 5 }, 5, { 5 });

    // Test 4: k = 1
    runTest(4, { 4, 2, 1, 5, 3 }, 1, { 4, 2, 1, 5, 3 });

    // Test 5: 递增数组
    runTest(5, { 1, 2, 3, 4, 5 }, 3, { 3, 4, 5 });

    // Test 6: 递减数组
    runTest(6, { 5, 4, 3, 2, 1 }, 3, { 5, 4, 3 });

    // Test 7: 全部相同
    runTest(7, { 7, 7, 7, 7 }, 2, { 7, 7, 7 });

    // Test 8: 含负数
    runTest(8, { -7, -8, 7, 5, 7, 1, 6, 0 }, 4, { 7, 7, 7, 7, 7 });

    // Test 9: 最大值在窗口起点
    runTest(9, { 9, 1, 1, 1, 1 }, 3, { 9, 1, 1 });

    return 0;
}