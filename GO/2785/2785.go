package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var chains = []int{}
var N int

func input() {
	var chain int
	fmt.Fscan(reader, &N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &chain)
		chains = append(chains, chain)
	}
}
func solve() int {
	sort.Ints(chains)

	link := N - 2
	for i, v := range chains {
		for j := v; j > 0; j-- {
			if link <= i {
				if link < i {
					link++
				}
				return N - 1 - link
			}
			link--
		}
	}
	return 0
}
func main() {
	defer writer.Flush()
	// f, err := os.Open("./2785.txt")
	// if err != nil {
	// 	fmt.Fprint(writer, err)
	// }
	// defer f.Close()
	reader = bufio.NewReader(os.Stdin)

	input()
	res := solve()
	fmt.Fprint(writer, res)
}
