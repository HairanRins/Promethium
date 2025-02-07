# Exploration algorithmique 🚀 

Les algorithmes sont des ensembles de règles ou d'instructions bien définies pour résoudre un problème spécifique.  
Ils peuvent varier en complexité, allant des tâches simples comme trier une liste à des problèmes plus complexes impliquant des structures de données avancées et des mathématiques appliquées. 

## 1. Algorithmes de Niveau Facile 

### Exemple : Tri d'une Liste 

**Sujet : Trier une liste de nombres**

Imaginez que vous êtes dans une bibliothèque et que vous devez ranger des livres par ordre alphabétique.
Vous prenez chaque livre, le comparez aux autres et les rangez dans l'ordre correct. 

* Pseudo-code : 

```
Pour chaque élément dans la liste:
    Comparez-le avec les éléments suivants.
    Si un élément est plus grand, échangez-les.
Répétez jusqu'à ce que la liste soit triée.
```

* Explication Mathématique : 

Le tri est une opération qui consiste à organiser des éléments selon une relation d'ordre (par exemple, ≤). 
Le nombre total de comparaisons nécessaires dépend de la taille de la liste et de la méthode de tri utilisée. 

* Implémentation : 
    -- JavaScript : 

```
function bubbleSort(arr) {
    let n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Échange
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
    return arr;
}

console.log(bubbleSort([64, 34, 25, 12, 22, 11, 90]));
``` 

## 2. Algorithmes de Niveau Moyen 

### Exemple : Recherche Dichotomique (Binary Search) 

**Sujet : Trouver un élément dans une liste triée**

Imaginez que vous jouez à un jeu où quelqu'un pense à un nombre entre 1 et 100. 
À chaque tour, vous demandez si le nombre est plus grand ou plus petit que votre supposition actuelle, réduisant ainsi la plage possible.

* Pseudo-code : 

```
Définir début = 0 et fin = longueur(liste) - 1.
Tant que début <= fin:
    Calculer milieu = (début + fin) // 2.
    Si liste[milieu] == cible:
        Retourner milieu.
    Sinon si liste[milieu] < cible:
        Définir début = milieu + 1.
    Sinon:
        Définir fin = milieu - 1.
Retourner -1 (si non trouvé).
``` 

* Explication Mathématique : 
La recherche dichotomique divise récursivement la liste en deux parties jusqu'à ce que l'élément soit trouvé.
La complexité temporelle est O(log n). 

* Implémentation :

``` 
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

console.log(binarySearch([1, 3, 5, 7, 9], 7)); // Output: 3
```

## 3. Algorithmes de Niveau Difficile 

### Exemple : Algorithme de Dijkstra (Plus court chemin dans un graphe pondéré) 

**Sujet : Trouver le plus court chemin entre deux nœuds dans un graphe**

Imaginez que vous êtes un voyageur cherchant le chemin le plus rapide entre deux villes sur une carte routière.  
Chaque route a une distance associée, et vous voulez minimiser la distance totale parcourue. 

* Pseudo-code : 

```
Initialiser distances[nœuds] = infini.
Définir distances[départ] = 0.
Créer une file de priorité et insérer (0, départ).
Tant que la file n'est pas vide:
    Extraire le nœud courant avec la plus petite distance.
    Pour chaque voisin du nœud courant:
        Calculer nouvelle_distance = distances[courant] + poids(courant -> voisin).
        Si nouvelle_distance < distances[voisin]:
            Mettre à jour distances[voisin] = nouvelle_distance.
            Insérer (nouvelle_distance, voisin) dans la file.
Retourner distances.
```

* Explication Mathématique : 
L'algorithme de Dijkstra utilise une file de priorité pour toujours explorer le nœud ayant la plus petite distance connue. 
Il garantit de trouver le chemin optimal dans un graphe avec des poids positifs. 

*  Implémentation :

```
class MinHeap {
    constructor() {
        this.heap = [];
    }
    // Ajouter des méthodes pour insert, extractMin, etc.
}

function dijkstra(graph, start) {
    const distances = {};
    const pq = new MinHeap();
    pq.insert(0, start);
    distances[start] = 0;

    while (!pq.isEmpty()) {
        const [dist, current] = pq.extractMin();
        for (const [neighbor, weight] of graph[current]) {
            const newDist = dist + weight;
            if (newDist < (distances[neighbor] || Infinity)) {
                distances[neighbor] = newDist;
                pq.insert(newDist, neighbor);
            }
        }
    }
    return distances;
}

// Exemple d'utilisation
const graph = {
    A: [['B', 1], ['C', 4]],
    B: [['A', 1], ['C', 2], ['D', 6]],
    C: [['A', 4], ['B', 2], ['D', 3]],
    D: [['B', 6], ['C', 3]]
};

console.log(dijkstra(graph, 'A'));
```

Les algorithmes sont des outils puissants pour résoudre des problèmes informatiques. 

