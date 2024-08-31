package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var puddles = [][2]int{}
var N, L int

func input(reader *bufio.Reader) {
	var s, e int
	fmt.Fscanf(reader, "%d %d\n", &N, &L)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d %d\n", &s, &e)
		puddles = append(puddles, [2]int{s, e})
	}
}
func solve() int {
	var count, idx int
	sort.Slice(puddles, func(i, j int) bool {
		return puddles[i][0] < puddles[j][0]
	})

	for _, puddle := range puddles {
		if idx >= puddle[0] && idx < puddle[1] {
			puddle[0] = idx
		} else if idx >= puddle[1] {
			continue
		}
		diff := puddle[1] - puddle[0]
		share := int(math.Ceil(float64(diff) / float64(L)))
		idx = puddle[0] + share*L
		count += share
	}
	return count
}
func main() {
	// f, _ := os.Open("./1911.txt")
	// defer f.Close()
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	input(reader)
	res := solve()
	fmt.Fprint(writer, res)
}
