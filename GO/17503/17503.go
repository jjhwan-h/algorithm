package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

var (
	reader  = bufio.NewReader(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	N, M, K int
)

type item struct {
	prefer, degree int
}
type PriorityQueue []*item

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].prefer < pq[j].prefer }
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(x any) {
	item := x.(*item)
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil

	*pq = old[:n-1]
	return item
}

func main() {
	defer writer.Flush()

	// file, _ := os.OpenFile("./17503.txt", os.O_RDONLY, 0644)
	// defer file.Close()
	// reader = bufio.NewReader(file)

	fmt.Fscan(reader, &N, &M, &K)

	var f, s int
	beers := make([]item, K)
	for i := range K {
		fmt.Fscan(reader, &f, &s)
		beers[i] = item{f, s}
	}

	sort.Slice(beers, func(i, j int) bool {
		return beers[i].degree < beers[j].degree
	})

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)

	var sum, cnt int
	res := -1
	for _, beer := range beers {
		heap.Push(&pq, &beer)
		cnt++
		sum += beer.prefer
		if pq.Len() > N {
			pair := heap.Pop(&pq).(*item)
			cnt--
			sum -= pair.prefer
		}
		if pq.Len() == N && sum >= M {
			res = beer.degree
			break
		}
	}

	fmt.Fprint(writer, res)
}
