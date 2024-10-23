package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}
type Blocks struct {
	top  []int
	down []int
}
type Res struct {
	min int
	res int
}

var N, H int

func input(io *IO) *Blocks {
	var tmp int
	blocks := &Blocks{}
	fmt.Fscanf(io.reader, "%d %d", &N, &H)
	for i := 1; i <= N; i++ {
		fmt.Fscan(io.reader, &tmp)
		if i%2 == 0 {
			blocks.top = append(blocks.top, tmp)
		} else {
			blocks.down = append(blocks.down, tmp)
		}
	}
	return blocks
}

func binarySearch(arr []int, t int) int {
	l, r := 0, len(arr)-1
	for l <= r {
		m := l + (r-l)/2
		if arr[m] >= t {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}

func countBlocking(arr []int, i int) int {
	idx := binarySearch(arr, i)
	if idx != -1 {
		return N/2 - idx
	}
	return 0
}

func solve(blocks *Blocks) *Res {
	min, res := 200001, 1

	sort.Slice(blocks.top, func(i, j int) bool {
		return blocks.top[i] < blocks.top[j]
	})
	sort.Slice(blocks.down, func(i, j int) bool {
		return blocks.down[i] < blocks.down[j]
	})

	for i := 1; i <= H; i++ {
		var cnt int
		cnt += countBlocking(blocks.down, i)
		cnt += countBlocking(blocks.top, H-i+1)
		if min > cnt {
			min = cnt
			res = 1
		} else if min == cnt {
			res++
		}
	}
	return &Res{min, res}
}

func main() {
	f, _ := os.Open("./3020.txt")
	defer f.Close()
	io := &IO{bufio.NewReader(f), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()
	blocks := input(io)
	res := solve(blocks)
	fmt.Fprintf(io.writer, "%d %d", res.min, res.res)
}
