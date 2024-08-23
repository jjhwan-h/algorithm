package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var gameMap [101][101]int
var res [101][101]int
var N int
var dir = [][2]int{{0, 1}, {1, 0}}

func input() {
	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Fscan(reader, &gameMap[i][j])
		}
	}
	gameMap[N-1][N-1] = -1
}
func DFS(y int, x int) int {
	if y == N-1 && x == N-1 {
		return 1
	}
	if res[y][x] != 0 {
		return res[y][x]
	}
	for i := 0; i < 2; i++ {
		ny := y + gameMap[y][x]*dir[i][0]
		nx := x + gameMap[y][x]*dir[i][1]
		if ny < N && nx < N && gameMap[ny][nx] != 0 {
			res[y][x] += DFS(ny, nx)
		}
	}
	return res[y][x]
}
func solve() {
	path := DFS(0, 0)
	fmt.Fprint(writer, path)
}
func main() {
	defer writer.Flush()
	// file, err := os.Open("./1890.txt")
	// if err != nil {
	// 	fmt.Fprint(writer, err)
	// }
	// defer file.Close()
	reader = bufio.NewReader(os.Stdin)

	input()
	solve()
}
