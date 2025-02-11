# Complexité algorithmique

C'est **une mesure de la quantité de ressources (temps et espace)** nécessaires pour exécuter un algorithme en fonction de la taille des données d'entrée. 
Elle est souvent exprimée en notation **O(f(n))** , où *f(n)* représente le comportement asymptotique de l'algorithme.

## Complexité Temps vs Complexité Espace 

#### Métaphore : Acheter une maison

Imaginez que vous cherchez une maison. Vous avez deux options : 
  * Une maison spacieuse avec beaucoup de chambres mais qui nécessite plus de maintenance.
  * Une maison plus petite, facile à entretenir, mais avec moins d'espace pour vos affaires.

Cela correspond respectivement à la **complexité en espace** (combien de mémoire utilise l'algorithme) et à la **complexité en temps** (combien d'étapes ou combien de calculs sont nécessaires).

---

C'est une mesure de l'efficacité d'un algorithme en fonction de la taille des données d'entrée. 
Elle permet de comprendre comment l'algorithme se comporte lorsque les données augmentent, que ce soit en termes de temps d'exécution (complexité temporelle) 
ou de mémoire utilisée (complexité spatiale). La notation la plus courante pour exprimer cette complexité est la notation **O(f(n))** , 
où *f(n)* représente une fonction qui décrit le comportement asymptotique de l'algorithme.

La complexité algorithmique mesure combien de ressources (temps et espace) un algorithme consomme en fonction de la taille de son entrée *(n)*.
Cela nous aide à évaluer l'efficacité d'un algorithme avant même de l'exécuter. 
 * **Complexité temporelle** : Combien d'opérations l'algorithme doit-il effectuer ?
 * **Complexité spatiale** : Combien de mémoire supplémentaire l'algorithme utilise-t-il ? 

L'objectif est de minimiser ces deux facteurs pour rendre l'algorithme aussi efficace que possible. 

## Comment Calculer la Complexité Algorithmique ? 

Pour calculer la complexité algorithmique, nous analysons le nombre d'opérations effectuées par l'algorithme en fonction de la taille de l'entrée *(n)*.

### Étapes pour calculer la complexité : 

1. **Identifier les opérations de base**:
  * Une opération de base est une action simple comme une comparaison, une addition, une affectation, etc. 
  * Par exemple, dans un tri, une comparaison entre deux éléments est une opération de base. 

2. **Compter les opérations en fonction de n :**
  * Comptez combien d'opérations sont nécessaires pour traiter une entrée de taille *n* .
  * Ignorez les constantes et les termes moins significatifs pour obtenir une approximation asymptotique. 

3. **Utiliser la notation O(f(n))** :
  * La notation O(f(n)) représente la croissance maximale du nombre d'opérations en fonction de *n* .
  * Par exemple, si un algorithme effectue environ *5n² + 3n + 7* opérations, sa complexité est *O(n²)*, car *n²* domine quand *n* devient grand.

## Types de Complexités Courantes

Voici les types de complexités les plus fréquemment rencontrés, classés par ordre croissant d'efficacité : 

**a) O(1) - Constante**

  * L'algorithme prend toujours le même temps, indépendamment de la taille de l'entrée.
  * Exemple : Accéder à un élément dans un tableau à un index donné.

  ```
  array[5]  // Temps constant, peu importe la taille du tableau.
  ```

**b) O(log n) - Logarithmique**

  * L'algorithme divise récursivement le problème en sous-problèmes plus petits.
  * Exemple : Recherche dichotomique.

   ``` 
   Si n = 1024, il ne faut que log₂(1024) = 10 étapes pour trouver un élément.
   ``` 

**c) O(n) - Linéaire**

  * L'algorithme traite chaque élément de l'entrée exactement une fois.
  * Exemple : Parcourir un tableau pour trouver le maximum.

  ```
  for (int i = 0; i < n; i++) {
    max = max(max, array[i]);
  }
  ```

**d) O(n log n) - Linéaire logarithmique**

  * L'algorithme combine une boucle linéaire avec une division logarithmique.
  * Exemple : Tri rapide (Quick Sort) ou fusion (Merge Sort).

  ```
  Diviser le tableau en deux parties, trier chaque partie, puis fusionner.
  ```

**e) O(n²) - Quadratique**

  * L'algorithme contient généralement deux boucles imbriquées.
  * Exemple : Tri bulle (Bubble Sort).

  ```
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (array[i] > array[j]) swap(array[i], array[j]);
    }
  }
  ```

**f) O(2ⁿ) - Exponentielle**

  * L'algorithme double le nombre d'opérations à chaque itération. 
  * Exemple : Résolution de problèmes NP-complets comme le sac à dos.

  ```
  Générer toutes les combinaisons possibles.
  ```

## Exemples Concrets avec Explications 

### Exemple 1 : Recherche Linéaire 
**Problème** : Trouver un élément dans un tableau non trié.

```
for (int i = 0; i < n; i++) {
    if (array[i] == target) return i;
}
return -1;
```

 * Nombre d'opérations : Au pire, vous devez parcourir tous les éléments *(n)*.
 * Complexité : O(n). 

### Exemple 2 : Recherche Dichotomique
**Problème** : Trouver un élément dans un tableau trié.

``` 
left = 0, right = n - 1;
while (left <= right) {
    mid = (left + right) / 2;
    if (array[mid] == target) return mid;
    else if (array[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

 * Nombre d'opérations : À chaque étape, la taille de la recherche est divisée par 2.
 * Complexité : O(log n).

### Exemple 3 : Tri Bulle (Bubble Sort) 
**Problème** : Trier un tableau.

```
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
    }
}
```

 * Nombre d'opérations : Pour chaque élément, vous comparez avec tous les autres.
 * Complexité : O(n²).

### Exemple 4 : Merge Sort

**Problème** : Trier un tableau en divisant et en conquérant.

```
function mergeSort(array):
    if length(array) <= 1:
        return array
    mid = length(array) / 2
    left = mergeSort(array[0:mid])
    right = mergeSort(array[mid:])
    return merge(left, right)
```

 * Nombre d'opérations : Chaque division divise le tableau en deux, et chaque fusion prend O(n).
 * Complexité : O(n log n).

## Pourquoi Ignorer les Constantes ? 

Lorsque nous analysons la complexité, nous ignorons les constantes et les termes moins significatifs parce que nous sommes intéressés par le comportement asymptotique de l'algorithme, 
c'est-à-dire comment il se comporte lorsque *n* devient très grand.

Par exemple : 
 * Si un algorithme effectue *5n² + 3n + 7* opérations, nous disons que sa complexité est *O(n²)*, car *n²* domine lorsque *n* augmente.


La complexité algorithmique est essentielle pour évaluer l'efficacité d'un algorithme. 
On peut calculer la complexité d'un algorithme et choisir celui qui convient le mieux à la situation.

 * Plus la complexité est faible, meilleure est l'efficacité de l'algorithme.
 * Dans la pratique, choisir un algorithme qui équilibre bien la complexité temporelle et spatiale selon les besoins.

En résumé : 
  * **O(1)** : Très rapide, mais rare.
  * **O(log n)** : Idéal pour les recherches.
  * **O(n)** : Bon pour les parcours simples.
  * **O(n log n)** : Performant pour les tris.
  * **O(n²)** : Acceptable pour des petites tailles, mais inefficace pour des grandes listes.
  * **O(2ⁿ)** : À éviter sauf pour des problèmes spécifiques.