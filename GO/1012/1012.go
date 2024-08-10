package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var N, M, K int
var area [51][51]int

type cabbage struct {
	x, y int
}

func initArea() {
	for i := 0; i < 51; i++ {
		for j := 0; j < 51; j++ {
			area[i][j] = 0
		}
	}
}

func bfs(cabbages []cabbage) (res int) {
	dirs := [][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	visited := [51][51]int{}

	for _, v := range cabbages {
		if visited[v.y][v.x] == 1 {
			continue
		}
		queue := [][2]int{{v.y, v.x}}
		for len(queue) > 0 {
			el := queue[0]
			queue = queue[1:]
			for _, dir := range dirs {
				nx, ny := el[1]+dir[1], el[0]+dir[0]
				if nx >= 0 && nx < M && ny >= 0 && ny < N && visited[ny][nx] == 0 && area[ny][nx] == 1 {
					visited[ny][nx] = 1
					queue = append(queue, [2]int{ny, nx})
				}
			}
		}
		res++
	}
	initArea()
	return
}

func input() (cabbages []cabbage) {
	var x, y int
	fmt.Fscan(reader, &M, &N, &K)
	for j := 0; j < K; j++ {
		fmt.Fscan(reader, &x, &y)
		cabbages = append(cabbages, cabbage{x, y})
		area[y][x] = 1
	}
	return
}
func solve() {
	defer writer.Flush()

	var T int
	fmt.Fscan(reader, &T)
	for i := 0; i < T; i++ {
		cabbages := input()
		res := bfs(cabbages)
		fmt.Fprintf(writer, "%d\n", res)
	}
}
func main() {
	// file, err := os.Open("./1012.txt")
	// if err != nil {
	// 	fmt.Println("can'not open file", err)
	// }
	// defer file.Close()
	reader = bufio.NewReader(os.Stdin)
	solve()
}
