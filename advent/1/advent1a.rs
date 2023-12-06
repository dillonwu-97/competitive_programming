use std::io;
use std::fs::File;
use std::io::BufRead;
use std::path::Path;

fn main() {
    let path = Path::new("./inp1a.txt");
    let file = File::open(&path).expect("Could not open the file");
    let reader = io::BufReader::new(file);
    let mut x: i32 = 0;
    for line in reader.lines() {
        match line {
            Ok(line) => {

                let mut s = String::new();
                for x in line.chars() {
                    if (x.is_digit(10)) {
                        s.push(x);
                        break;
                    }
                }

                for x in line.chars().rev() {
                    if (x.is_digit(10)) {
                        s.push(x);
                        break;
                    }
                }
                x += s.parse::<i32>().unwrap();
                
            },
            Err(e) => println!("{}", e) ,
        }
    }
    println!("{}", x);
}
