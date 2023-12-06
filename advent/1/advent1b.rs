use std::io;
use std::fs::File;
use std::io::BufRead;
use std::path::Path;

fn main() {
    let path = Path::new("./inp1a.txt");
    let file = File::open(&path).expect("Could not open the file");
    let reader = io::BufReader::new(file);
    let mut x: i32 = 0;
    let nums = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    let snums = ["1", "2", "3", "4", "5", "6", "7", "8", "9"];
    for line in reader.lines() {
        match line {
            Ok(line) => {


                let mut s = line;
                //let mut s = String::new();

                /*
                for (x,y) in nums.iter().zip(snums.iter()) {
                    println!("{} {}", x, y);
                }
                */
                let mut ret = String::new();
                let mut temp = String::new();
                let chars: Vec<char> = s.chars().collect();
                let mut flag = false;

                // what is collect() in rust?
                for (i,x) in s.char_indices() {
                    for (j,&n) in nums.iter().enumerate() {
                        if s.len() - i >= n.len() {
                            temp = chars[i..i+n.len()].iter().collect::<String>();
                            //println!("{} {} {}", temp, i, i+n.len());
                            if temp == n {
                                //println!("FOUND {}", temp);
                                ret.push_str(snums[j]);
                                flag = true;
                                break;
                            }
                        }
                    }
                    if flag == true {
                        break;
                    }
                    if x.is_digit(10) {
                        ret.push(x);
                        break;
                    }
                }

                flag = false;

                for (i,x) in s.char_indices().rev() {
                    for (j,&n) in nums.iter().enumerate() {
                        if s.len() - i >= n.len() {
                            temp = chars[i..i+n.len()].iter().collect::<String>();
                            if temp == n {
                                println!("FOUND {}", temp);
                                ret.push_str(snums[j]);
                                flag = true;
                                break;
                            }
                        }
                    }
                    if flag == true {
                        break;
                    }
                    if x.is_digit(10) {
                        ret.push(x);
                        break;
                    }
                }

                println!("{}, {}", s, ret);
                x += ret.parse::<i32>().unwrap();
                
                /*
                for (num, digit) in nums.iter().zip(snums.iter()) {
                    s = s.replace(num, digit);    
                }

                for x in s.chars() {
                    if (x.is_digit(10)) {
                        ret.push(x); 
                        break;
                    }
                }

                for x in s.chars().rev() {
                    if (x.is_digit(10)) {
                        ret.push(x);
                        break;
                    }
                }

                */
                /*
                for x in line.chars().rev() {
                    if (x.is_digit(10)) {
                        s.push(x);
                        break;
                    }
                }
                */

                
            },
            Err(e) => println!("{}", e) ,
        }
    }
    println!("x is {}", x);
}
