# Basics 

Si les données étaient un langage, les structures de données seraient sa grammaire. Beaucoup de développeurs sous-estiment leur importance.
Pourtant, elles sont la base de tout.

Les Array et Matrix sont les plus basiques mais aussi les plus utilisées.

Parfaites pour les données séquentielles et les grilles. Attention toutefois aux performances sur les grandes dimensions.

Stack et Queue suivent les principes LIFO et FIFO. Elles sont indispensables pour gérer les flux de données et constituent la base des systèmes asynchrones.

Les Tree et BST excellent dans la représentation des relations hiérarchiques. Les BST optimisent particulièrement les recherches.

La HashMap est probablement la structure la plus puissante pour le mapping clé-valeur.

Elle offre un accès en O(1) dans le meilleur des cas, mais nécessite une gestion attentive des collisions.

Le Heap, souvent sous-utilisé par méconnaissance, est indispensable pour les priorités et le tri, notamment dans les algorithmes de graphes.

La Linked List brille par sa flexibilité en insertion/suppression, mais son accès séquentiel peut être limitant.

À utiliser avec parcimonie.

Les Graph et Union Find excellent dans la modélisation des relations complexes. Indispensables pour les réseaux sociaux ou le GPS, ce sont les plus versatiles mais aussi les plus complexes.

Le Trie, optimisé pour les chaînes de caractères, est parfait pour l'autocomplétion. Une structure sous-estimée mais puissante.

Ce qui différencie un développeur junior d'un senior ?
Le junior utilise les structures qu'il connaît, le senior choisit les structures optimales.

Les algorithmes sont importants, mais sans les bonnes structures de données, ils ne sont rien.


![algo7](https://github.com/user-attachments/assets/dfcd0fdd-92bc-40a5-996b-b09f05a541a6)

Voici les 7 complexités essentielles :

1. O(1) - Temps constant
Le temps d'exécution ne change pas, peu importe la taille des données.
Ex : Accéder à un élément d'un tableau par son index.

2. O(log n) - Temps logarithmique
Le temps augmente doucement quand les données grandissent.
Ex : Recherche binaire dans un tableau trié.

3. O(n) - Temps linéaire
Le temps augmente proportionnellement aux données.
Ex : Parcourir un tableau pour trouver un élément.

4. O(n log n) - Temps linéarithmique
Un peu plus lent que le temps linéaire.
Ex : Les algorithmes de tri comme QuickSort.

5. O(n²) - Temps quadratique
Le temps augmente au carré de la taille des données.
Ex : Le tri à bulles qui compare chaque paire d'éléments.

6. O(2^n) - Temps exponentiel
Le temps double à chaque nouvelle donnée.
Ex : Générer tous les sous-ensembles possibles.

7. O(n.) - Temps factoriel
Le temps explose littéralement avec la taille des données.
Ex : Générer toutes les permutations possibles.

