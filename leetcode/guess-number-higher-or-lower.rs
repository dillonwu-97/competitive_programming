/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */
impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let b :u32 = n as u32;
        unsafe fn solve(lo: u32, hi: u32) -> u32 {
            let mut mid = (lo+hi) / 2;
            let c:i32 = mid as i32;
            if (guess(c) == 0) {
                return mid;
            } else if (guess(c) == 1) {
                return solve(mid+1, hi);
            } else {
                return solve(lo, mid);
            }
        }
        return solve(1, b) as i32;
    }
}