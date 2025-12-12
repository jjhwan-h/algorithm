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
	N, M, K int

	dx      = [4]int{0, 0, 1, -1}
	dy      = [4]int{1, -1, 0, 0}
	m       = [101][101]int{}
	visited = [101][101]bool{}
	queue   = []pos{}
)

type pos struct {
	y, x int
}

func main() {
	f, _ := os.OpenFile("./2583.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	scanner.Split(bufio.ScanWords)
	defer writer.Flush()

	//입력
	M, N, K = scanInt(), scanInt(), scanInt()
	var lx, ly, rx, ry int
	//초기화
	for range K {
		lx, ly, rx, ry = scanInt(), scanInt(), scanInt(), scanInt()
		for i := 0; i < M; i++ {
			for j := 0; j < N; j++ {
				if i >= ly && i < ry && j >= lx && j < rx {
					m[i][j] = 1
				}
			}
		}
	}

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if m[i][j] != 1 {
				queue = append(queue, pos{i, j})
			}
		}
	}

	//빈 구역 체크
	for len(queue) != 0 {
		p := queue[0]
		queue = queue[1:]

		if m[p.y][p.x] == 1 || m[p.y][p.x] == 2 {
			continue
		} else {
			m[p.y][p.x] = 2
		}

		for i := range 4 {
			ny := p.y + dy[i]
			nx := p.x + dx[i]

			if ny >= 0 && ny < M && nx >= 0 && ny < N && m[ny][nx] == 0 {
				m[ny][nx] = 2
				queue = append(queue, pos{ny, nx})
			}
		}
	}

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if m[i][j] == 2 {
				fmt.Fprint(writer, dfs(i, j), " ")
			}
		}
	}
}

func dfs(y, x int) int {
	if visited[y][x] {
		return -1
	}

	for i := range 4 {
		ny := dy[i] + y
		nx := dx[i] + x

		if ny >= 0 && ny < M && nx >= 0 && ny < N && m[ny][nx] == 0 {
			visited[ny][nx] = true
			dfs(ny, nx)
		}
	}
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
