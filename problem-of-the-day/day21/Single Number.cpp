/*
The key idea is to use bitwise operations to keep track of the count of each bit position.
 By doing so, we can identify the bits that have appeared once, twice, or three times.
When a bit appears for the first time (ones is 0 and the bit is toggled), it is stored in ones.
When a bit appears for the second time (ones is 1 and the bit is toggled), it is removed from ones and stored in twos.
When a bit appears for the third time (ones is 0 and the bit is toggled), it is removed from both ones and twos.
By the end of the iteration, the bits that remain in ones represent the bits of the single number that appeared only once, 
while the bits in twos represent bits that appeared three times (which is not possible).
*/

int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }