package main

import (
	"bufio"
	"fmt"
	"os"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

var (
	io = &IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	N  int
)

func solve() {
	var buildings []int
	var tmp, res int
	fmt.Fscan(io.reader, &N)
	fmt.Fscan(io.reader, &tmp)
	buildings = append(buildings, tmp)

	for i := 1; i < N; i++ {
		fmt.Fscan(io.reader, &tmp)
		for j := len(buildings) - 1; j >= 0; j-- {
			if buildings[j] <= tmp {
				buildings = buildings[:j]
				res += len(buildings)
			} else {
				break
			}
		}
		buildings = append(buildings, tmp)
	}

	length := len(buildings)
	res += (length*(length+1))/2 - length

	fmt.Fprintln(io.writer, res)
}

func main() {
	defer io.writer.Flush()
	f, _ := os.Open("./6198.txt")
	defer f.Close()
	io.reader = bufio.NewReader(f)

	solve()
}
