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