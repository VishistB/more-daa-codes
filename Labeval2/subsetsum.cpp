#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, int target, vector<int>& path, int curr, vector<vector<int>>& res){
    if(target==0){
        res.push_back(path);
        return;
    }
    if(curr==nums.size()){
        return;
    }
    path.push_back(nums[curr]);
    backtrack(nums, target - nums[curr], path, curr + 1, res);
    path.pop_back();
    backtrack(nums, target, path, curr + 1, res);
}

vector<vector<int>> subsetSum(vector<int> nums , int target){
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(),nums.end());
    backtrack(nums, target,path, 0,res);
    return res;
}

int main()
{
    vector<int> nums={3, 1, 5, 9, 12};
    int target=10;
    vector<vector<int>> sol=subsetSum(nums,target);
    for (auto& r : sol) {
        for (int i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}