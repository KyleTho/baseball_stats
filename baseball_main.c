//
//  baseball_main.c
//  
//
//  Created by Kyle Hecker on 6/11/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>


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
    char buffer[50];
    char *endptr;
    
    printf("Please enter the average number of home runs for a specific \n"
           "player for a specific time frame (e.g. a single game): ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        
        errno = 0;
        
        home_runs = strtod(buffer, &endptr);
        if (endptr == buffer) {
            printf("Error: No valid number was found.\n");
        } else if (errno == ERANGE) {
            printf("Error: The number is too large or too small.\n");
        } else {
            printf("Successfully parsed number: %lf\n", home_runs);
    }
    
    
    printf("Please enter the number of home runs you would like to find the probability for: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Input error\n");
            
        errno = 0;
            
        home_runs = strtod(buffer, &endptr);
        if (endptr == buffer) {
            printf("Error: No valid number was found.\n");
        } else if (errno == ERANGE) {
            printf("Error: The number is too large or too small.\n");
        } else {
            printf("Successfully parsed number: %lf\n", home_runs);
    }
    
    double poisson_count = poisson(home_runs, hr_predict);
    double poisson_sum = 0;
    
    if (hr_predict > 0) {
        for (int i=0; i < hr_predict; i++) {
            poisson_sum += poisson(home_runs, i);
        }
        
        double final_poisson = 1.0 - poisson_sum;
        
        printf("The probability of the player hitting at least %d home run(s) is %lf", hr_predict, final_poisson);
        
    } else {
        printf("The probability of the player hitting %d home runs is %lf", hr_predict, poisson_count);
    }
    
    return 0;
}
