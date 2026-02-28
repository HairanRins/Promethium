# Promethium

Dedans je mettrais mes notes et mes connaissances ou acquis en algorithmes et structures de données

### Algorithmes de Tri

#### Tri à Bulles

> **Définition** : Le tri à bulles est un algorithme de tri simple qui parcourt la liste de manière répétée, compare des éléments adjacents et les échange s’ils ne sont pas dans le bon ordre.

**Étapes principales :**

1. Parcourir la liste plusieurs fois.
2. Comparer chaque élément avec le suivant.
3. Échanger les éléments s'ils sont dans le mauvais ordre.
4. Répéter jusqu'à ce que la liste soit triée.

> **Complexité Temporelle** : O(n²) dans le pire des cas (si la liste est triée dans l'ordre inverse).

#### Tri par Insertion

> **Définition** : Le tri par insertion est un algorithme de tri simple qui construit progressivement le tableau trié en insérant chaque nouvel élément à la bonne position dans la partie triée du tableau.

**Étapes :**

1. Commencez par le deuxième élément (le premier est considéré comme trié).
2. Comparez l'élément actuel avec ceux du tableau trié et insérez-le à sa place appropriée.
3. Répétez jusqu'à ce que tous les éléments soient triés.

> **Complexité Temporelle** :

- Pire cas : O(n²)
- Meilleur cas : O(n) (si la liste est déjà triée)
- Cas moyen : O(n²)

---

#### Tri par Sélection

> **Définition** : Le tri par sélection parcourt le tableau pour trouver l'élément minimum dans la partie non triée, puis l’échange avec le premier élément de cette partie, et continue jusqu’à ce que la liste soit triée.

**Étapes :**

1. Recherchez l'élément minimum dans le tableau non trié.
2. Échangez-le avec le premier élément non trié.
3. Répétez le processus pour le reste du tableau.

> **Complexité Temporelle** :

- Pire cas : O(n²)
- Meilleur cas : O(n²)
- Cas moyen : O(n²)

---

#### Tri Rapide (Quick Sort)

> **Définition** : Le tri rapide est un algorithme de tri par division et conquête. Il sélectionne un pivot, partitionne les autres éléments en sous-tableaux (inférieurs et supérieurs au pivot) et les trie récursivement.

**Étapes :**

1. Choisissez un élément comme pivot.
2. Partitionnez le tableau en éléments inférieurs et supérieurs au pivot.
3. Appliquez récursivement le même processus aux sous-tableaux.

> **Complexité Temporelle** :

- Pire cas : O(n²) (lorsque le tableau est déjà trié)
- Meilleur cas : O(n log n)
- Cas moyen : O(n log n)

---

#### Tri par Fusion (Merge Sort)

> **Définition** : Le tri par fusion est un algorithme de type "diviser pour régner". Il divise le tableau en deux moitiés, trie chaque moitié, puis fusionne les moitiés triées pour former un tableau entièrement trié.

**Étapes :**

1. Divisez le tableau en deux moitiés.
2. Triez chaque moitié de manière récursive.
3. Fusionnez les deux moitiés triées en un tableau unique.

> **Complexité Temporelle** :

- Pire cas : O(n log n)
- Meilleur cas : O(n log n)
- Cas moyen : O(n log n)

---

#### Tri par Tas (Heap Sort)

> **Définition** : Le tri par tas utilise une structure de données appelée tas binaire. Il crée un tas maximal à partir du tableau, extrait l’élément maximal et le place en fin de tableau, en répétant jusqu’à obtenir une liste triée.

**Étapes :**

1. Construisez un tas maximal à partir du tableau.
2. Échangez l'élément maximal avec le dernier élément du tas.
3. Réduisez la taille du tas et restaurez la propriété du tas.
4. Répétez jusqu'à ce que tous les éléments soient triés.

> **Complexité Temporelle** :

- Pire cas : O(n log n)
- Meilleur cas : O(n log n)
- Cas moyen : O(n log n)

---

#### Tri par Base (Radix Sort)

> **Définition** : Le tri par base est un algorithme de tri non-comparatif. Il regroupe les éléments selon leurs valeurs numériques à chaque position décimale, en partant du chiffre le moins significatif vers le plus significatif.

**Étapes :**

1. Traitez les chiffres de chaque élément à partir du chiffre le moins significatif jusqu'au plus significatif.
2. Utilisez un algorithme de tri stable (comme le tri par comptage) pour trier les éléments par chiffre.
3. Répétez pour chaque chiffre jusqu'à ce que le tableau soit trié.

> **Complexité Temporelle** :

- Pire cas : O(nk), où n est le nombre d'éléments et k le nombre de chiffres.
- Meilleur cas : O(nk)
- Cas moyen : O(nk)
