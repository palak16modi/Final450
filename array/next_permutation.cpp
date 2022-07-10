#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutation(vector<int>& nums) {
	if(nums.size()==1) return nums; 
    int index1 = nums.size()-1;
    int index2 = nums.size();
    int i=nums.size()-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i==-1){
        reverse(nums.begin(), nums.end());
    }
    else{
        index1 = i;
        i=nums.size()-1;
        while(i>=0 && nums[i]<=nums[index1]){
            i--;
        }
        index2 = i;
        swap(nums[index1],nums[index2]);
        reverse(nums.begin()+index1+1, nums.end());
    }
    return nums;
}

int main(int argc, char** argv) {
	vector<int> nums = {1,4,5,3};
	nums = nextPermutation(nums);
	for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
	return 0;
}
