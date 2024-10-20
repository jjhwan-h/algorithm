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

// func printRes(io *IO, res [101]int) {
// 	fmt.Fprintln(io.writer, len(res))
// 	for i := 0; i < len(res); i++ {
// 		fmt.Fprintln(io.writer, res[i])
// 	}
// }

var cnt int

func DFS(arr []int, visited []bool, idx int) int {
	if visited[idx] {
		return idx
	}
	visited[idx] = true
	return DFS(arr, visited, arr[idx])
}

func solve(io *IO, arr []int) {
	var res []int
	for i := 1; i < len(arr); i++ {
		visited := make([]bool, len(arr)+1)
		idx := DFS(arr, visited, i)
		if idx == i {
			cnt++
			res = append(res, i)
		}
	}
	fmt.Fprintln(io.writer, cnt)
	for j := 0; j < len(res); j++ {
		fmt.Fprintln(io.writer, res[j])
	}
}

func input(io *IO) []int {
	var arr []int
	var N, tmp int
	arr = append(arr, 0)
	fmt.Fscan(io.reader, &N)
	for i := 1; i <= N; i++ {
		fmt.Fscan(io.reader, &tmp)
		arr = append(arr, tmp)
	}
	return arr
}

func main() {
	f, _ := os.Open("./2668.txt")
	defer f.Close()

	io := &IO{bufio.NewReader(f), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	arr := input(io)
	solve(io, arr)
}
