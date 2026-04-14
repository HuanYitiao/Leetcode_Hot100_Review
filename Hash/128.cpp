#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        int res = 0;
        for (int x : st)
        {
            if (st.end() != st.find(x - 1))
            {
                continue;
            }

            int y   = x + 1;
            int can = 0;
            while (st.end() != st.find(y))
            {
                y++;
            }
            res = max(res, y - x);
        }
        return res;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<int> input, int expected)
{
    Solution sol;
    int      result = sol.longestConsecutive(input);

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
    cout << "===== LeetCode 128. 最长连续序列 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { 100, 4, 200, 1, 3, 2 }, 4);

    // Test 2: 较长连续序列
    runTest(2, { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }, 9);

    // Test 3: 含重复元素
    runTest(3, { 1, 0, 1, 2 }, 3);

    // Test 4: 空数组
    runTest(4, {}, 0);

    // Test 5: 单个元素
    runTest(5, { 42 }, 1);

    // Test 6: 全部相同
    runTest(6, { 7, 7, 7, 7 }, 1);

    // Test 7: 负数
    runTest(7, { -3, -2, -1, 0, 1 }, 5);

    // Test 8: 不相邻的多段
    runTest(8, { 10, 11, 12, 1, 2, 100, 101, 102, 103 }, 4);

    return 0;
}