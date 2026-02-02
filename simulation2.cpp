#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector rpcomp2(int n, double lamb, double mu, double sigma) {
    NumericVector resultats(n);
    
    for (int i = 0; i < n; i++) {
        int N = R::rpois(lamb);
        double somme = 0.0;
        
        for (int j = 0; j < N; j++) {
            somme += R::rlnorm(mu, sigma);
        }
        
        resultats[i] = somme;
    }
    
    return resultats;
}
