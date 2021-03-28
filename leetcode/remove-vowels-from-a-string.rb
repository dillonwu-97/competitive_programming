# @param {String} s
# @return {String}
def remove_vowels(s)
    vowels = ["a", "e", "i", "o", "u"]
    mystring = ""
    s.each_char do |i|
        if !vowels.include? i
            mystring << i
        end
    end
    return mystring
end