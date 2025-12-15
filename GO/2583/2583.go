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
	N, M, K int

	dx    = [4]int{0, 0, 1, -1}
	dy    = [4]int{1, -1, 0, 0}
	m     = [101][101]bool{}
	queue = []pos{}
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
					m[i][j] = true
				}
			}
		}
	}

	var cnt int
	var areas []int
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if !m[i][j] {
				m[i][j] = true
				queue = append(queue, pos{i, j})
				areas = append(areas, bfs())
				cnt++
			}
		}
	}

	sort.Slice(areas, func(i, j int) bool {
		return areas[i] < areas[j]
	})

	fmt.Fprintln(writer, cnt)
	for _, v := range areas {
		fmt.Fprint(writer, v, " ")
	}
}

func bfs() int {
	area := 1
	//빈 구역 체크
	for len(queue) != 0 {
		p := queue[0]
		queue = queue[1:]

		for i := range 4 {
			ny := p.y + dy[i]
			nx := p.x + dx[i]
			if ny >= 0 && ny < M && nx >= 0 && nx < N && !m[ny][nx] {
				m[ny][nx] = true
				queue = append(queue, pos{ny, nx})
				area++
			}
		}
	}
	return area
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
