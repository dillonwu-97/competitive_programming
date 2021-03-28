class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=1;
        while(j < nums.size()) {
            if (nums[i] == 0 && nums[j]!=0) {
                swap(i, j, nums);
                // cout << nums[i] <<" " << nums[j] << endl;
                i+=1;
                j+=1;
            } else if (nums[i] == 0 && nums[j] == 0) {
                // cout << "hello" << endl;
                j+=1;
            }  else {
                j+=1;
                i+=1;
            }
        }
    }
        void swap(int i, int j, vector<int>& nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    };