# @param {Integer[]} candies
# @param {Integer} extra_candies
# @return {Boolean[]}
def kids_with_candies(candies, extra_candies)
    m = candies.max
    ret = []
    candies.each do |i|
        if i + extra_candies >= m
            ret.push(true)
        else
            ret.push(false)
        end
    end
    return ret
end