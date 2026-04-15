#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
//   public:
//     int trap(vector<int>& height)
//     {
//         if (height.size() <= 2)
//         {
//             return 0;
//         }

//         vector<int> pre_max(height.size());
//         pre_max[0] = height[0];
//         for (int i = 1; i < height.size(); i++)
//         {
//             pre_max[i] = max(height[i], pre_max[i - 1]);
//         }

//         vector<int> sur_max(height.size());
//         sur_max[height.size() - 1] = height[height.size() - 1];
//         for (int i = height.size() - 2; i >= 0; i--)
//         {
//             sur_max[i] = max(height[i], sur_max[i + 1]);
//         }

//         int res = 0;
//         for (int i = 0; i < height.size(); i++)
//         {
//             res += min(pre_max[i], sur_max[i]) - height[i];
//         }
//         return res;
//     }
// };

class Solution
{
  public:
    int trap(vector<int>& height)
    {
        if (height.size() <= 2)
        {
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;

        int pre_max = 0;
        int sur_max = 0;

        int res = 0;
        while (l < r)
        {
            pre_max = max(pre_max, height[l]);
            sur_max = max(sur_max, height[r]);
            if (pre_max < sur_max)
            {
                res += pre_max - height[l];
                l++;
            }
            else
            {
                res += sur_max - height[r];
                r--;
            }
        }

        return res;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> input, int expected)
{
    Solution sol;
    int      result = sol.trap(input);

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
    cout << "===== LeetCode 42. 接雨水 =====" << endl << endl;

    // Test 1: 经典用例
    runTest(1, { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, 6);

    // Test 2: V形
    runTest(2, { 4, 2, 0, 3, 2, 5 }, 9);

    // Test 3: 空数组
    runTest(3, {}, 0);

    // Test 4: 单个元素
    runTest(4, { 5 }, 0);

    // Test 5: 两个元素
    runTest(5, { 3, 7 }, 0);

    // Test 6: 递增（不接水）
    runTest(6, { 1, 2, 3, 4, 5 }, 0);

    // Test 7: 递减（不接水）
    runTest(7, { 5, 4, 3, 2, 1 }, 0);

    // Test 8: 两端高中间低
    runTest(8, { 5, 0, 0, 0, 5 }, 15);

    // Test 9: 全部相同
    runTest(9, { 3, 3, 3, 3 }, 0);

    // Test 10: 锯齿形
    runTest(10, { 0, 1, 0, 1, 0, 1, 0 }, 2);

    return 0;
}