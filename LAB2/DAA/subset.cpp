#include <iostream>
#include <vector>

void findSubsets(const std::vector<int> &set, int targetSum, std::vector<int> &currentSubset, int index)
{
    if (targetSum == 0)
    {
        std::cout << "Subset found: ";
        for (int num : currentSubset)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    if (index == set.size() || targetSum < 0)
    {
        return;
    }

    // Include the current element in the subset
    currentSubset.push_back(set[index]);
    findSubsets(set, targetSum - set[index], currentSubset, index + 1);

    // Exclude the current element from the subset
    currentSubset.pop_back();
    findSubsets(set, targetSum, currentSubset, index + 1);
}

int main()
{
    std::vector<int> set = {1, 2, 5, 6, 8};
    int targetSum = 9;
    std::vector<int> currentSubset;

    findSubsets(set, targetSum, currentSubset, 0);

    if (currentSubset.empty())
    {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
