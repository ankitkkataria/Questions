#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  void f(int i, vector<int> &temp, int &currSum, vector<int> &candidates,
         int target, vector<vector<int>> &res) {

    if (i >= candidates.size())
      return;

    for (auto num : temp) {
      cout << num << " ";
    }

    cout << endl;
    if (currSum > target)
      return;

    if (currSum == target) {
      res.push_back(temp);
      return;
    }
    temp.push_back(candidates[i]);
    currSum += candidates[i];
    f(i, temp, currSum, candidates, target, res);
    temp.pop_back();
    currSum -= candidates[i];

    f(i + 1, temp, currSum, candidates, target, res);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    int currSum = 0;
    f(0, temp, currSum, candidates, target, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> candidates = {2, 3};
  int target = 7;
  Solution1 sol;
  vector<vector<int>> res = sol.combinationSum(candidates, target);
  cout << "resulting array is " << endl;
  for (auto vec : res) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
