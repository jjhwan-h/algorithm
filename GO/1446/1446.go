package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	writer  = bufio.NewWriter(os.Stdout)
	scanner = bufio.NewScanner(os.Stdin)
)

func main() {
	f, _ := os.OpenFile("./1446.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	N, D := ScanInt(), ScanInt()
	road := make([]int, D+1)
	shortCuts := make([][3]int, N)
	for i := range N {
		shortCuts[i] = [3]int{ScanInt(), ScanInt(), ScanInt()}
	}

	sort.Slice(shortCuts, func(i, j int) bool {
		return shortCuts[i][0] < shortCuts[j][0]
	})

	// 거리 갱신
	for i := range D + 1 {
		road[i] = i
	}

	for i := range N {
		if shortCuts[i][1]-shortCuts[i][0] <= shortCuts[i][2] || shortCuts[i][1] > D { // 지름길 X
			continue
		}
		dist := road[shortCuts[i][0]] + shortCuts[i][2]
		if road[shortCuts[i][1]] > dist {
			road[shortCuts[i][1]] = dist
		}

		// 거리 갱신
		for j := shortCuts[i][1] + 1; j <= D; j++ {
			if road[j] > road[j-1]+1 {
				road[j] = road[j-1] + 1
			}
		}
	}

	fmt.Fprintln(writer, road[D])
}

func ScanInt() int {
	scanner.Scan()
	v, _ := strconv.Atoi(scanner.Text())
	return v
}
