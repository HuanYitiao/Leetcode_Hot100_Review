#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxArea(vector<int>& height)
    {
        int left  = 0;
        int right = height.size() - 1;
        int res   = 0;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            res      = max(res, area);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> input, int expected)
{
    Solution sol;
    int      result = sol.maxArea(input);

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
    cout << "===== LeetCode 11. 盛最多水的容器 =====" << endl << endl;

    // Test 1: 经典用例
    runTest(1, { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49);

    // Test 2: 最小输入（两个元素）
    runTest(2, { 1, 1 }, 1);

    // Test 3: 递增
    runTest(3, { 1, 2, 3, 4, 5 }, 6);

    // Test 4: 递减
    runTest(4, { 5, 4, 3, 2, 1 }, 6);

    // Test 5: 两端最高
    runTest(5, { 10, 1, 1, 1, 10 }, 40);

    // Test 6: 中间最高
    runTest(6, { 1, 1, 100, 100, 1, 1 }, 100);

    // Test 7: 全部相同
    runTest(7, { 3, 3, 3, 3 }, 9);

    // Test 8: 一边极短
    runTest(8, { 1, 1000 }, 1);

    return 0;
}