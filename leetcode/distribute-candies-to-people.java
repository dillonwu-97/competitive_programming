class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        // keep track of the number of people
        int[] store = new int[num_people];
        int pos = 0;
        int can = 0;
        while (candies - can > 0) {
            can++;
            store[pos] = store[pos] + can;
            //System.out.println(pos);
            if (pos == num_people - 1) {
                pos = 0;
            } else {
                pos++;
            }
            candies = candies - can;
        }
        //leftover
        System.out.println(pos);
        if (pos == num_people) {
            pos = 0;
        }
        store[pos] = store[pos] + candies;
        return store;
                    }
}