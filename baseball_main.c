//
//  baseball_main.c
//  
//
//  Created by Kyle Hecker on 6/11/26.
//

#include <math.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    
    return n * factorial(n - 1);
        
}


double poisson(double lambda, int x) {
    
    double e_value = exp(-lambda);
    
    double lamda_x = pow(lambda, x);
    
    int denominator = factorial(x);
    
    return (e_value * lamda_x) / denominator;
    
}

int main() {
    
    double home_runs;
    int hr_predict;
    
    printf("Please enter the average number of home runs for a specific /n"
           "player for a specific time frame (e.g. a single game): ");
    
    while (scanf("%lf", &home_runs) != 1) {
        printf("Invalid input. Please enter a number.");
    }
    
    printf("Please enter the number of home runs you would like to find the probability for: ");
    
    while (scanf("%d", &hr_predict) != 1) {
        printf("Invalid input. Please enter an integer.");
    }
    
    double poisson_count = poisson(home_runs, hr_predict);
    
    if (hr_predict > 1) {
        for (int i=0; i < hr_predict; i++) {
            double poisson_sum = poisson_count + poisson_sum;
        }
        
        
        printf("The probability of the player hitting %d home runs is %lf", hr_predict, poisson_sum);
    }
    
    printf("The probability of the player hitting %d home runs is %lf", hr_predict, poisson_count);
    
    
    
}
