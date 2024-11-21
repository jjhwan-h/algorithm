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
)

func input() []int {
	N := scanInt()
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		num := scanInt()
		arr[i] = num
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
	return arr
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func abs(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

func solve() {
	N := scanInt()
	for i := 0; i < N; i++ {
		arr := input()
		res := 0
		num1 := arr[0]
		num2 := arr[1]
		for j := 2; j < len(arr); j++ {
			if j%2 == 0 {
				res = max(abs(num1, arr[j]), res)
				num1 = arr[j]
			} else {
				res = max(abs(num2, arr[j]), res)
				num2 = arr[j]
			}
		}
		fmt.Fprintln(writer, res)
	}
}

func main() {
	defer writer.Flush()

	f, _ := os.Open("./11497.txt")
	defer f.Close()
	scanner = bufio.NewScanner(f)
	scanner.Split(bufio.ScanWords) //단어 단위

	solve()
}

func scanInt() int {
	scanner.Scan()
	v, _ := strconv.Atoi(scanner.Text())
	return int(v)
}
