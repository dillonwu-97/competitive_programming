impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut ret = vec![];
        let mut count = 0;
        for i in nums.iter() {
            count = 0;
            for j in nums.iter() {
                if (j < i) {
                    count +=1;
                }   
            }
            ret.push(count);
        }
        return ret;
            }
}