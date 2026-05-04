#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }

            if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<vector<int>> matrix, int target, bool expected)
{
    Solution sol;
    bool     result = sol.searchMatrix(matrix, target);

    bool pass = (result == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << "  (expected " << (expected ? "true" : "false") << ", got " << (result ? "true" : "false") << ")";
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 240. 搜索二维矩阵 II =====" << endl << endl;

    vector<vector<int>> mat1 = {
        { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 }
    };

    // Test 1: 存在
    runTest(1, mat1, 5, true);

    // Test 2: 不存在
    runTest(2, mat1, 20, false);

    // Test 3: 左上角
    runTest(3, mat1, 1, true);

    // Test 4: 右下角
    runTest(4, mat1, 30, true);

    // Test 5: 右上角
    runTest(5, mat1, 15, true);

    // Test 6: 左下角
    runTest(6, mat1, 18, true);

    // Test 7: 单元素存在
    runTest(7, { { 5 } }, 5, true);

    // Test 8: 单元素不存在
    runTest(8, { { 5 } }, 3, false);

    // Test 9: 单行
    runTest(9, { { 1, 3, 5, 7 } }, 3, true);

    // Test 10: 单列
    runTest(10, { { 1 }, { 3 }, { 5 } }, 4, false);

    return 0;
}