class Solution {
public:
    int minimizeXor(int num1, int num2) {
         int count = __builtin_popcount(num2); // Count the set bits in num2

        int result = 0;

        // Set bits in result where num1 has bits set, starting from the most significant bit

        for (int i = 31; i >= 0 && count > 0; --i) {

            if (num1 & (1 << i)) {

                result |= (1 << i);

                --count;

            }

        }

        // If there are still bits to set, set them in the least significant positions

        for (int i = 0; i < 32 && count > 0; ++i) {

            if (!(result & (1 << i))) {

                result |= (1 << i);

                --count;

            }

        }

        return result;
    }
};