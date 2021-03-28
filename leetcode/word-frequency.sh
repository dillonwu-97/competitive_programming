# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s '\t ' '\n' | sort | uniq -c | sort -n -r | awk '{print $2
    , $1}'