#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void simulate_coin(int trials, double bias) {
    int heads = 0;
    for (int i = 0; i < trials; i++) {
        
        if (((double)rand() / RAND_MAX) < bias) {
            heads++;
        }
    }
    printf("Bias: %.2f | Trials: %d | Experimental Heads Prob: %f\n", 
           bias, trials, (double)heads / trials);
}

int main() {
    
    srand(time(NULL)); 

    printf("--- Running Coin Simulation ---\n");
    
    simulate_coin(10000, 0.50);
    
    
    simulate_coin(10000, 0.75);

    return 0;
}
