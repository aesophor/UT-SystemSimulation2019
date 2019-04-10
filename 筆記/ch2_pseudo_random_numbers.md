## CH2 PSEUDO RANDOM NUMBERS
1.  **TRUE RANDOM vs PSEUDO-RANDOM**
      * **True Random** :
        * unpredictable
        * unreproducible
        * useful in: cryptography
      * **Pseudo Random** (or simply **"Random"**) :
        * the same seed will generate the same sequence of random numbers (deterministic)
        * they will pass a number of statistical tests (which are designed to test various properties of random numbers)
        * useful in: computer simulation

2. **PSEUDO RANDOM NUMBERS**
    * **An acceptable method** for generating random numbers must satisfy...
      * Uniformly distributed in [0,1]
      * Statistically independent (one event conveys no information about the other)
      * Reproducible
      * Non-repeating for any length
    * Pseudo-random numbers are within [0,1]
    * All other random numbers -> "random / stochastic variates"
    * Can be used:
      * by themselves
      * to generate random numbers from other distributions (random variates, stochastic variates)

3. **GENERATION METHODS**
    * **Linear Congruential Generators** :
      * uses the following recursive relationship to generate random numbers: 
        * `Xi+1 = (a * Xi + c) % m` where `X0, a, c < m`
        * X0 is the seed number.
        ```
         e.g.,
		 1 3 7 5 **1 3 7 5** (period = 4)
		 1 8 5 2 9 6 3 0 7 4 **1 8 5 2 9** (period = 10)
		 ```
      * numbers generated are between 0 ~ (m-1)
      * divide each of them by m to obtain uniformly distributed random numbers between 0 ~ 1
      * will generate periodic, repeated subsequences

    * **Quadratic Congruential Generators** :
      *  `Xi+1 = (a1 * (Xi^2) + a2 * Xi-1 + c) % m`

    * **Additive Congruential Generators** :
      *  `Xi+1 = (a1Xi + a2Xi-1 + ... + akXi-k) % m`

	* **Tausworthe Generators** : 
	  * additive congruential generators when m = 2
	  * i.e., `Xi = (a1Xi-1 + a2Xi-2 + ... + anXi-n) % 2;`
	  * Xi will either be 0 or 1
	  * the bits (0 or 1) generated can be put together sequentially to form an integer

    * **The Lagged Fibonacci Generators** :
      *  based on fibonacci sequence
      * `Xn = (Xn-j OP Xn-k) % m` where
        * `0 < j < k`
        * OP can be `+, -, *, /, XOR`
      * produces better random numbers
      * but requires memory of k past states

    * **The Mersenne Twister ** :
      * its maximum period is 2^19937 - 1 (higher than many other generators)
      * its output has very good statistical properties

4. **STATISTICAL TESTS**
    * Five statistical tests:
      * frequency test
      * serial test
      * auto-correlation test
      * runs test
      * chi-square test (從實驗結果，看分布是否符合我們的假設)
