#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> candidate;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = candidate.find(target - nums[i]);
            if (candidate.end() != it)
            {
                return { i, it->second };
            }
            else
            {
                candidate[nums[i]] = i;
            }
        }
        return {};
    }

    void printVector(std::vector<int> nums)
    {
        for (int n : nums)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Solution         sol;
    std::vector<int> vec1    = { 2, 7, 11, 15 };
    int              target1 = 9;
    sol.printVector(sol.twoSum(vec1, target1));

    std::vector<int> vec2    = { 3, 2, 4 };
    int              target2 = 6;
    sol.printVector(sol.twoSum(vec2, target2));

    std::vector<int> vec3    = { 3, 3 };
    int              target3 = 6;
    sol.printVector(sol.twoSum(vec3, target3));

    return 0;
}