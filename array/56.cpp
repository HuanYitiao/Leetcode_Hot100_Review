#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto& p : intervals)
        {
            if (!ans.empty() && p[0] <= ans.back()[1])
            {
                ans.back()[1] = max(p[1], ans.back()[1]);
            }
            else
            {
                ans.push_back(p);
            }
        }
        return ans;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<vector<int>> input, vector<vector<int>> expected)
{
    Solution sol;
    auto     result = sol.merge(input);

    // 排序以便比较（题目不要求输出顺序，但排序后好对比）
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << endl << "  expected: ";
        for (auto& v : expected)
            cout << "[" << v[0] << "," << v[1] << "] ";
        cout << endl << "  got:      ";
        for (auto& v : result)
            cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 56. 合并区间 =====" << endl << endl;

    // Test 1: 基本用例
    runTest(1, { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } }, { { 1, 6 }, { 8, 10 }, { 15, 18 } });

    // Test 2: 相邻但不重叠（端点相等算重叠）
    runTest(2, { { 1, 4 }, { 4, 5 } }, { { 1, 5 } });

    // Test 3: 单个区间
    runTest(3, { { 1, 4 } }, { { 1, 4 } });

    // Test 4: 完全重叠
    runTest(4, { { 1, 4 }, { 2, 3 } }, { { 1, 4 } });

    // Test 5: 无重叠
    runTest(5, { { 1, 2 }, { 3, 4 }, { 5, 6 } }, { { 1, 2 }, { 3, 4 }, { 5, 6 } });

    // Test 6: 需要先排序（乱序输入）
    runTest(6, { { 5, 6 }, { 1, 2 }, { 3, 4 } }, { { 1, 2 }, { 3, 4 }, { 5, 6 } });

    // Test 7: 全部合并成一个
    runTest(7, { { 1, 4 }, { 2, 5 }, { 3, 6 } }, { { 1, 6 } });

    // Test 8: 包含关系
    runTest(8, { { 1, 10 }, { 2, 3 }, { 4, 5 } }, { { 1, 10 } });

    // Test 9: 乱序+复杂合并
    runTest(9, { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, { 1, 10 } }, { { 1, 10 } });

    return 0;
}