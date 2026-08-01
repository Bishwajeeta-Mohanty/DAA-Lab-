#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for time()

void simulate_coin(int trials, double bias) {
    int heads = 0;
    for (int i = 0; i < trials; i++) {
        // Generates a random decimal between 0.0 and 1.0
        if (((double)rand() / RAND_MAX) < bias) {
            heads++;
        }
    }
    printf("Bias: %.2f | Trials: %d | Experimental Heads Prob: %f\n", 
           bias, trials, (double)heads / trials);
}

int main() {
    // RECTIFICATION: Seed the random number generator with the current time
    srand(time(NULL)); 

    printf("--- Running Coin Simulation ---\n");
    // Test Fair Coin (50% chance)
    simulate_coin(10000, 0.50);
    
    // Test Biased Coin (75% chance)
    simulate_coin(10000, 0.75);

    return 0;
}