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

func input(io *IO) [][2]int {
	var n, x, y int
	fmt.Fscan(io.reader, &n)

	arr := make([][2]int, n+2)
	for i := 0; i < n+2; i++ {
		fmt.Fscan(io.reader, &x, &y)
		arr[i] = [2]int{x, y}
	}

	return arr
}

func dist(a [2]int, b [2]int) int {
	x := a[0] - b[0]
	if x < 0 {
		x = -x
	}
	y := a[1] - b[1]
	if y < 0 {
		y = -y
	}
	return x + y
}

func BFS(arr [][2]int) bool {
	visited := make([]int, len(arr))
	que := [][2]int{arr[0]}
	visited[0] = 1

	for len(que) > 0 {
		el := que[0]
		que = que[1:]

		if dist(el, arr[len(arr)-1]) <= 1000 {
			return true
		}
		for i := 1; i < len(arr)-1; i++ {
			if visited[i] == 1 {
				continue
			}
			if dist(el, arr[i]) <= 1000 {
				visited[i] = 1
				que = append(que, arr[i])
			}
		}
	}
	return false
}

func solve(io *IO) {
	var N int
	fmt.Fscan(io.reader, &N)

	for i := 0; i < N; i++ {
		arr := input(io)
		flag := BFS(arr)

		if flag {
			fmt.Fprintln(io.writer, "happy")
		} else {
			fmt.Fprintln(io.writer, "sad")
		}
	}
}

func main() {
	f, _ := os.Open("./9205.txt")
	defer f.Close()

	io := IO{bufio.NewReader(f), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	solve(&io)
}
