# Comparaison de Méthodes de Simulation en R et Rcpp

## Contexte
Ce projet a été réalisé dans le cadre du Master Actuariat à l'Institut de Science Financière et d’Assurances.  
L’objectif est de comparer différentes méthodes de simulation d’une variable aléatoire X définie par :

X = C₁ + C₂ + ... + Cₙ  
où N ~ Poisson(λ) et les Cᵢ ~ Log-Normale(μ, σ), N et Cᵢ indépendantes.

Le projet compare :  
1. Simulation en R pur  
2. Simulation en R avec code C intégré  
3. Simulation via Rcpp  
4. Simulation Rcpp parallélisée avec OpenMP  

Le but est de mesurer la vitesse d’exécution et vérifier que les moyennes et variances empiriques sont proches des valeurs théoriques.

## Objectifs du projet
- Simuler efficacement X avec différentes méthodes.  
- Comparer la vitesse d’exécution.  
- Vérifier la précision statistique des résultats.  
- Explorer la parallélisation et l’optimisation avec Rcpp et OpenMP.

## Fonctionnalités principales
- Fonction `rpcomp(n, lamb, mu, sigma)` en R et C pour générer X.  
- Fonction `convolRcpp` pour la convolution en Rcpp.  
- Fonction `convolRcppP` pour la parallélisation avec OpenMP.  
- Comparaison des temps d’exécution et des statistiques (moyenne, variance).  

## Compétences développées
- Programmation R avancée et Rcpp  
- Intégration de code C dans R  
- Parallélisation avec OpenMP  
- Optimisation et analyse de performance  
- Validation statistique et vérification de modèles

## Fichiers inclus
- PDF du rapport complet avec méthodologie et résultats.  
- Scripts R (`convol.simple.R`, `convol.dec.R`, `convol-rcpp.R`)  
- Code C/Rcpp (`r-convol.c`, `convol-rcpp.cpp`)  

## Remerciements
Nous remercions notre enseignant ALEXIS BIENVENÜE pour son encadrement et ses conseils méthodologiques tout au long du projet.

