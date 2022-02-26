impl Solution {
    pub fn min_moves_to_seat(seats: Vec<i32>, students: Vec<i32>) -> i32 {
                let mut seats = seats.to_vec();
        seats.sort();
        let mut students = students.to_vec();
        students.sort();
        let mut ret = 0;
        let mut temp;
        for i in 0..seats.len() {
            temp = students[i] - seats[i];
            temp = temp.abs();
            ret += temp;
            // println!("{}, {}", students[i], seats[i]);
        }
        return ret;
    }
}