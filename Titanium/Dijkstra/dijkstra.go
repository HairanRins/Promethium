package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	node	string
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq)}
func (pq PriorityQueue) Less(i, j int) bool  {
	return pq[i].priority < pq[j].priority
}
func (pq PriorityQueue) Swap(i, j int)  {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(*Item)
    item.index = len(*pq)
    *pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    item.index = -1
    *pq = old[0 : n-1]
    return item
}

func dijkstra(graph map[string]map[string]int, start string) map[string]int {
    distances := make(map[string]int)
    pq := &PriorityQueue{}
    heap.Init(pq)
    heap.Push(pq, &Item{node: start, priority: 0})
    distances[start] = 0

    for pq.Len() > 0 {
        item := heap.Pop(pq).(*Item)
        current := item.node
        for neighbor, weight := range graph[current] {
            newDist := distances[current] + weight
            if _, ok := distances[neighbor]; !ok || newDist < distances[neighbor] {
                distances[neighbor] = newDist
                heap.Push(pq, &Item{node: neighbor, priority: newDist})
            }
        }
    }
    return distances
}

func main() {
    graph := map[string]map[string]int{
        "A": {"B": 1, "C": 4},
        "B": {"A": 1, "C": 2, "D": 6},
        "C": {"A": 4, "B": 2, "D": 3},
        "D": {"B": 6, "C": 3},
    }
    fmt.Println(dijkstra(graph, "A"))  // map[A:0 B:1 C:3 D:6]
}