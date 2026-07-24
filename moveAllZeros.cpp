#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> nums = {1,0,5,0,3,0,9};
    
    int count = 0;

    for (int i = 0; i<nums.size();i++){
        if (nums[i] != 0){
            nums[count] = nums[i];
            count++;
        }
    }

    while (count < nums.size()){
        nums[count] = 0;
        count++;
    }

    for (int num : nums){
        cout << num << endl;
    }

}