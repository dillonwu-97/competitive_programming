impl Solution {
    pub fn number_of_steps(num: i32) -> i32 {
        if (num == 0) { return 0; }
        let mut ret = 0;
        let mut n = num;
        while(n != 1) {
            if (n & 1 == 1) {
                ret += 2;
            } else {
                ret += 1;
            }
            n >>= 1;
            // println!("{}", num);
        }
        return ret + 1;
            }
}