#include <Rcpp.h>
#include <omp.h>
using namespace Rcpp;


// [[Rcpp::export]]
NumericVector rpcomp2_omp_basic(int n, double lambda, double mu, double sigma) {
    NumericVector resultats(n);

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        int N = R::rpois(lambda);
        double somme = 0.0;

        for (int j = 0; j < N; j++) {
            somme += R::rlnorm(mu, sigma);
        }

        resultats[i] = somme;
    }

    return resultats;
}

// [[Rcpp::export]]
NumericVector rpcomp2_omp_static(int n, double lambda, double mu, double sigma, int chunk = 100) {
    NumericVector resultats(n);

    #pragma omp parallel for schedule(static, chunk)
    for (int i = 0; i < n; i++) {
        int N = R::rpois(lambda);
        double somme = 0.0;

        for (int j = 0; j < N; j++) {
            somme += R::rlnorm(mu, sigma);
        }

        resultats[i] = somme;
    }

    return resultats;
}

// [[Rcpp::export]]
NumericVector rpcomp2_omp_dynamic(int n, double lambda, double mu, double sigma, int chunk = 100) {
    NumericVector resultats(n);

    #pragma omp parallel for schedule(dynamic, chunk)
    for (int i = 0; i < n; i++) {
        int N = R::rpois(lambda);
        double somme = 0.0;

        for (int j = 0; j < N; j++) {
            somme += R::rlnorm(mu, sigma);
        }

        resultats[i] = somme;
    }

    return resultats;
}

// [[Rcpp::export]]
NumericVector rpcomp2_omp_auto(int n, double lambda, double mu, double sigma) {
    NumericVector resultats(n);

    #pragma omp parallel for schedule(auto)
    for (int i = 0; i < n; i++) {
        int N = R::rpois(lambda);
        double somme = 0.0;

        for (int j = 0; j < N; j++) {
            somme += R::rlnorm(mu, sigma);
        }

        resultats[i] = somme;
    }

    return resultats;
}


