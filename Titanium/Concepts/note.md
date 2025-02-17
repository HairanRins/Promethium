# Des concepts importants à savoir 

## 1. Récursivité

La récursivité est une technique où une fonction s'appelle elle-même pour résoudre un problème.
Elle est souvent utilisée pour décomposer un problème complexe en sous-problèmes plus simples.

**Exemple simple :**

Calculer la factorielle d'un nombre. 

```
def factorielle(n):
    if n == 0 or n == 1:  # Cas de base
        return 1
    else:
        return n * factorielle(n - 1)  # Appel récursif

print(factorielle(5))  # Output: 120
``` 

**Points clés :**

* Cas de base : Condition qui arrête la récursivité. 
* Appel récursif : La fonction s'appelle elle-même avec un problème plus petit. 

**Utilisations courantes :**

 * Parcours d'arbres ou de graphes. 
 * Algorithmes de tri (ex : tri rapide, tri fusion). 
 * Résolution de problèmes mathématiques (ex : suite de Fibonacci). 

## 2. Itération 

L'itération est une technique où une boucle (comme `for` ou `while`) est utilisée pour répéter un ensemble d'instructions jusqu'à ce qu'une condition soit remplie.

**Exemple simple :** 

Calculer la factorielle d'un nombre avec une boucle. 

```  
def factorielle(n):
    resultat = 1
    for i in range(1, n + 1):
        resultat *= i
    return resultat

print(factorielle(5))  # Output: 120
```

**Comparaison avec la récursivité :**

 * Itération : Utilise moins de mémoire (pas de pile d'appels). 
 * Récursivité : Plus intuitive pour certains problèmes (ex : parcours d'arbres). 

## 3. Diviser pour régner (Divide and Conquer) 

Technique qui divise un problème en sous-problèmes plus petits, résout chaque sous-problème, puis combine les résultats pour résoudre le problème initial.

**Exemple simple :**

Tri fusion (Merge Sort). 

```
def tri_fusion(tableau):
    if len(tableau) <= 1:
        return tableau
    milieu = len(tableau) // 2
    gauche = tri_fusion(tableau[:milieu])  # Diviser
    droite = tri_fusion(tableau[milieu:])  # Diviser
    return fusionner(gauche, droite)  # Combiner

def fusionner(gauche, droite):
    resultat = []
    i = j = 0
    while i < len(gauche) and j < len(droite):
        if gauche[i] < droite[j]:
            resultat.append(gauche[i])
            i += 1
        else:
            resultat.append(droite[j])
            j += 1
    resultat.extend(gauche[i:])
    resultat.extend(droite[j:])
    return resultat
``` 

**Utilisations courantes :**

 * Tri fusion, tri rapide.
 * Multiplication de matrices (algorithme de Strassen).
 * Recherche binaire.

## 4. Programmation dynamique 

Technique qui résout des problèmes complexes en les décomposant en sous-problèmes plus simples et en stockant les résultats intermédiaires pour éviter les calculs redondants.

Exemple simple : 

Calcul de la suite de Fibonacci. 

```
def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 2:
        return 1
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]

print(fibonacci(10))  # Output: 55
```

**Utilisations courantes :**

 * Problèmes d'optimisation (ex : sac à dos). 
 * Plus long sous-ensemble commun (LCS). 
 * Plus court chemin (algorithme de Floyd-Warshall). 

## 5. Backtracking

Technique qui explore toutes les solutions possibles à un problème en revenant en arrière (backtrack) lorsqu'une solution partielle ne mène pas à une solution complète. 

**Exemple simple :**

Résolution du problème des N reines. 

```
def est_valide(plateau, ligne, col):
    for i in range(ligne):
        if plateau[i] == col or abs(plateau[i] - col) == abs(i - ligne):
            return False
    return True

def placer_reines(plateau, ligne, n):
    if ligne == n:
        return True
    for col in range(n):
        if est_valide(plateau, ligne, col):
            plateau[ligne] = col
            if placer_reines(plateau, ligne + 1, n):
                return True
            plateau[ligne] = -1
    return False

n = 8
plateau = [-1] * n
placer_reines(plateau, 0, n)
print(plateau)
```

**Utilisations courantes :**

 * Problèmes de placement (ex : N reines, Sudoku). 
 * Génération de permutations et combinaisons. 

---

**Pile (Stack)**	Structure de données "Last In, First Out" (LIFO).

**File (Queue)**	Structure de données "First In, First Out" (FIFO).

**Graphe**	        Ensemble de nœuds connectés par des arêtes.

**Arbre**	        Graphe sans cycle, avec une racine et des nœuds enfants.

**Hashage**	        Technique pour mapper des données à des clés uniques (ex : dictionnaires).

**Récursivité terminale**    Récursivité où l'appel récursif est la dernière opération (optimisable).

