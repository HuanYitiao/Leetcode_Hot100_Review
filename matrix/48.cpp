#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[matrix.size() - i - 1][j]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// ============== 测试框架 ==============

void runTest(int testNum, vector<vector<int>> input, vector<vector<int>> expected)
{
    Solution sol;
    sol.rotate(input);

    bool pass = (input == expected);
    cout << "Test " << testNum << ": " << (pass ? "✅ PASS" : "❌ FAIL");
    if (!pass)
    {
        cout << endl << "  expected:" << endl;
        for (auto& row : expected)
        {
            cout << "    [";
            for (int i = 0; i < row.size(); i++)
                cout << row[i] << (i < row.size() - 1 ? "," : "");
            cout << "]" << endl;
        }
        cout << "  got:" << endl;
        for (auto& row : input)
        {
            cout << "    [";
            for (int i = 0; i < row.size(); i++)
                cout << row[i] << (i < row.size() - 1 ? "," : "");
            cout << "]" << endl;
        }
    }
    cout << endl;
}

int main()
{
    cout << "===== LeetCode 48. 旋转图像 =====" << endl << endl;

    // Test 1: 3x3
    runTest(1, { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }, { { 7, 4, 1 }, { 8, 5, 2 }, { 9, 6, 3 } });

    // Test 2: 4x4
    runTest(2,
            { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } },
            { { 15, 13, 2, 5 }, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } });

    // Test 3: 1x1
    runTest(3, { { 1 } }, { { 1 } });

    // Test 4: 2x2
    runTest(4, { { 1, 2 }, { 3, 4 } }, { { 3, 1 }, { 4, 2 } });

    return 0;
}