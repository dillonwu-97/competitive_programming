impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        // can't do this because length needs to be a constant
        // let a: [i32; arr.len()] = [0; arr.len()];
                let mut a = vec![0; arr.len()+1];
        let mut ret = 0;
        for i in 0..arr.len() {
            a[i+1] = arr[i] + a[i];
            // println!("{}, {}", i+1, a[i+1]);
        }
        let mut temp = 0;
        for i in (1..a.len()).step_by(2) {
            for j in (0..a.len()-i) {
                ret += (a[j+i] - a[j]);
            }
        }
        return ret;
    }
}