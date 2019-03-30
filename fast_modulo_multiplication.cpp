#include <iostream>
#include <math.h>

/*
Fast Modulo Multiplication (also known as Exponential Squaring
or Repeated Squaring)

CodeChef tutorial link,
https://discuss.codechef.com/t/a-tutorial-on-fast-modulo-multiplication-exponential-squaring/2899
*/

/* Naive implementation */
int slow_mod_mult(long long int base, long long int exp, long long int mod) {
    long long int ans = 1;
    // iterates through each exponent
    for (int i = 1; i <= exp; i++) {
        ans = (ans * base) % mod;
    }

    return ans % mod;
}

// recursive version of fast_exp2()
// ( a * b ) mod x = ( (a mod x) * (b mod x) ) mod x
/*
A brief analysis of this formula (an intuitive analysis if you prefer),
based both on its recursive formulation and on its implementation allows
us to see that the formula uses only O(log2n) squarings and O(log2n)
multiplications!

This is a major improvement over the most naive method described in the
beginning of this text, where we used much more multiplication operations
*/
long long int fast_exp_recursive(long long int base, long long int exp, long long int mod) {
    if (exp == 1) return base;
    else {
        if (exp % 2 == 0) {
            long long int base1 = pow(fast_exp_recursive(base, exp/2, mod), 2);
            return base1 >= mod ? base1 % mod : base1;
        } else {
            long long int ans = base * pow(fast_exp_recursive(base, (exp - 1)/2, mod), 2);
            return ans >= mod ? ans % mod : ans;
        }
    }
}
// iterative version
// 10^9 = 10^2 * 10^2 * 10^2 * 10^2 * 10^1
/* The 2k-ary method for repeated squaring.
Besides the recursive method detailed above, we can use yet another insight
which allows us to compute the value of the desired power.

The main idea is that we can expand the exponent in base 2 (or more generally,
in base 2k, with k >= 1) and use this expansion to achieve the same result as
above, but, this time, using less memory.
*/
long long int fast_exp_iterative(long long int base, int exp, long long int mod){
    long long int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

int main()
{
    int base = 9;
    int exp = 55;
    // find 3^55 mod 7 + 10^9
    // todo: fix recursive version
    std::cout << fast_exp_iterative(base, 56, 1000000007) << std::endl;
    std::cout << fast_exp_recursive(base, 56, 1000000007) << std::endl;
    std::cout << slow_mod_mult(base, 56, 1000000007) << std::endl;

    return 0;
}


