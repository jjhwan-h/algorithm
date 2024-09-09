package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var N int

func input(reader *bufio.Reader) (lines [][2]int) {
	var s, e int
	fmt.Fscan(reader, &N)
	lines = make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &s, &e)
		lines[i][0] = s
		lines[i][1] = e
	}
	return
}
func solve(lines [][2]int) (cnt int) {
	start := -1000000001
	end := -1000000001
	sort.Slice(lines, func(i, j int) bool {
		return lines[i][0] < lines[j][0]
	})

	for _, line := range lines {
		if line[0] <= end {
			if line[1] > end {
				end = line[1]
			}
		} else if line[0] > end {
			cnt += end - start
			start = line[0]
			end = line[1]
		}
	}
	cnt += end - start
	return
}
func main() {
	// f, _ := os.Open("./2170.txt")
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	lines := input(reader)
	cnt := solve(lines)
	fmt.Fprint(writer, cnt)
}
