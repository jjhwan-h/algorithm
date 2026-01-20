package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	visited = make([][251]bool, 251)
	banner  = make([][251]bool, 251)
	dx      = [8]int{-1, -1, -1, 0, 0, 1, 1, 1}
	dy      = [8]int{-1, 0, 1, -1, 1, -1, 0, 1}
)

func main() {
	f, _ := os.OpenFile("./14716.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	M, N := scanInt(), scanInt()

	for i := range M {
		for j := range N {
			n := intToBool(scanInt())
			banner[i][j] = n
		}
	}

	cnt := 0
	for i := range M {
		for j := range N {
			if banner[i][j] && !visited[i][j] {
				visited[i][j] = true
				DFS(i, j)
				cnt++
			}
		}
	}
	fmt.Fprintln(writer, cnt)
}

func DFS(i, j int) {
	for k := 0; k < 8; k++ {
		nx := j + dx[k]
		ny := i + dy[k]
		if ny >= 0 && ny < 251 && nx >= 0 && nx < 251 && !visited[ny][nx] && banner[ny][nx] == true {
			visited[ny][nx] = true
			DFS(ny, nx)
		}
	}
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func intToBool(n int) bool {
	return n == 1
}
