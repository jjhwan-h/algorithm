package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type node struct {
	num, d int
}

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	tree    = make([][]int, 500_001)
	visited = make([]bool, 500_001)
)

func main() {
	f, _ := os.OpenFile("./15900.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	// scanner.Buffer(make([]byte, 1024), 1<<20)

	N := scanInt()
	for range N - 1 {
		a, b := scanInt(), scanInt()
		tree[b] = append(tree[b], a)
		tree[a] = append(tree[a], b)
	}

	var res int
	queue := make([]node, 0, N)
	queue = append(queue, node{1, 0})
	visited[1] = true
	for len(queue) != 0 {
		last := len(queue) - 1
		cur := queue[last]
		queue = queue[:last]

		num, dep := cur.num, cur.d
		if len(tree[num]) == 1 && num != 1 { // leaf
			res += dep
			continue
		}

		for _, nn := range tree[num] {
			if visited[nn] {
				continue
			}
			visited[nn] = true
			queue = append(queue, node{nn, dep + 1})
		}
	}

	if res%2 == 0 {
		fmt.Fprintln(writer, "No")
	} else {
		fmt.Fprintln(writer, "Yes")
	}

}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
