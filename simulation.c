// AKATCHI DANIEL 
#include <R.h>
#include <Rmath.h>

void simuler_X_C(int *n, double *lambda, double *mu, double *sigma, double *resultats) {
    // Synchronisation avec le générateur aléatoire de R
    GetRNGstate();
    
    int N;
    double somme;
    int i, j;
    
    for (i = 0; i < *n; i++) {
        // Simuler N ~ Poisson(λ)
        N = rpois(*lambda);
        somme = 0.0;
        
        // Simuler les C_i ~ LogNormale(μ, σ) et les sommer
        for (j = 0; j < N; j++) {
            somme += rlnorm(*mu, *sigma);
        }
        
        resultats[i] = somme;
    }
    
    // Resynchronisation avec R
    PutRNGstate();
}