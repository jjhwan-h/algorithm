package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	N       int
)

type pillar struct {
	pos, height int
}

func main() {
	defer writer.Flush()

	f, _ := os.OpenFile("./2304.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)
	scanner.Split(bufio.ScanWords)

	pillars := input()

	sort.Slice(pillars, func(i, j int) bool {
		return pillars[i].pos < pillars[j].pos
	})

	var height, hightest int
	for idx, p := range pillars {
		if height < p.height {
			height = p.height
			hightest = idx
		}
	}

	res := solve(pillars, hightest)
	fmt.Fprint(writer, res)
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func input() []pillar {
	N = scanInt()
	pillars := make([]pillar, N)
	for i := range N {
		p, h := scanInt(), scanInt()
		pillars[i] = pillar{p, h}
	}
	return pillars
}

func solve(pillars []pillar, hightestIdx int) int {
	var (
		idx, res int
		high     pillar
	)
	high = pillar{pos: pillars[0].pos, height: pillars[0].height}
	for idx = 0; idx <= hightestIdx; idx++ {
		if pillars[idx].height >= high.height {
			res += (pillars[idx].pos - high.pos) * high.height
			high = pillars[idx]
		}
	}

	idx--
	res += pillars[idx].height

	high = pillar{pos: pillars[N-1].pos, height: pillars[N-1].height}
	for i := N - 1; i >= idx; i-- {
		if pillars[i].height >= high.height {
			res += (high.pos - pillars[i].pos) * high.height
			high = pillars[i]
		}
	}

	return res
}
