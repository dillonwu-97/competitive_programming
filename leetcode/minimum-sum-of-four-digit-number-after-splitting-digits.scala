object Solution {
    def minimumSum(num: Int): Int = {
        val l = num.toString.map(_.asDigit).toList.sorted
        // println(l)
        val num1 = l(0)* 10 + l(2)
        val num2 = l(1)*10 + l(3)
        return num1 + num2
    }
}