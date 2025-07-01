#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> nums = {5, 2, 3, 6, 4, 7, 1};

  int minToRight= nums[0];
  int bestLeft = 0;
  int bestRight = 0;
  int maxDifference = 0;
  
  for (int i = 1; i < nums.size(); i++) {

    if (nums[i] - minToRight> maxDifference) {
      bestLeft = minToRight;
      bestRight = nums[i];
      maxDifference = nums[i] - minToRight;
    }

    minToRight= min(nums[i], minToRight);
  }

  cout << "max differnce " << maxDifference << endl;
  cout << "left boundry " << bestLeft << endl;
  cout << "right boundry " << bestRight << endl;

  return 0;
}
