#include <iostream>
#include <vector>
#include <algorithm>

class solution
{
  public:
    int findDuplicate(const std::vector<int>& nums) {
        int begin = 0, end=  nums.size()-1;
        int mid = (begin+end)/2;
        int countSmaller(0), countLarger(0);
        for (auto i : nums) {
            if (i <= mid)
                countSmaller++;
            else
                countLarger++;
        }
        if (mid-begin+1 < countSmaller)
            end = mid;
        else if (end-mid < countLarger)
            begin = mid+1;

        while (end-begin != 1) {
            mid = (begin+end)/2;
            countSmaller = 0, countLarger = 0;
            for (auto i : nums) {
                if (i <= mid)
                    countSmaller++;
                else
                    countLarger++;
            }
            if (mid-begin+1 < countSmaller)
                end = mid;
            else if (end-mid < countLarger)
                begin = mid+1;
        }

        countSmaller = 0, countLarger = 0;
        for (auto i : nums) {
            if (i == begin)
                countSmaller++;
            else if (i == end)
                countLarger++;
        }

        if (countSmaller > 1)
            return begin;
        return end;
    }
};

int main()
{
    std::vector<int> nums{2,3,4,5,3,3,3};
    // int ret = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    // int sum = std::accumulate(nums.begin(), nums.end(), 0,
    //                           [](int x, int y){ return x+y; });

    // std::cout << "xor = " << ret << std::endl;
    // std::cout << "sum = " << sum << std::endl;

    // int n = nums.size()-1;
    // std::cout << "sum of 1 to " << n << " = " << n*(n+1)/2 << std::endl;
    // std::cout << "1 xor 2 = " << std::bit_xor<int>()(1,2) << std::endl;

    solution soln;
    int dup = soln.findDuplicate(nums);
    std::cout << "The duplicate number is:\n"
              << dup << std::endl;
}
