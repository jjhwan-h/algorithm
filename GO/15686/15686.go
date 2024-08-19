package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var N, M int
var home [][2]int
var chicken [][2]int
var res = 2147000000

func input() {
	var n int
	fmt.Fscanf(reader, "%d %d", &N, &M)
	for i := 1; i <= N; i++ {
		for j := 1; j <= N; j++ {
			fmt.Fscan(reader, &n)
			if n == 1 {
				home = append(home, [2]int{i, j})
			} else if n == 2 {
				chicken = append(chicken, [2]int{i, j})
			}
		}
	}
}
func absInt(n int) int {
	if n < 0 {
		return -n
	} else {
		return n
	}
}
func calDist(arr []int) int {
	sum := 0
	for _, h := range home {
		less := 2147000000
		for _, c := range arr {
			dist := absInt(h[0]-chicken[c][0]) + absInt(h[1]-chicken[c][1])
			if less > dist {
				less = dist
			}
		}
		sum += less
	}
	return sum
}
func combination(n int, idx int, arr []int) {
	if n == M {
		d := calDist(arr)
		if res > d {
			res = d
		}
	}
	for i := idx + 1; i < len(chicken); i++ {
		arr = append(arr, i)
		combination(n+1, i, arr)
		arr = arr[:len(arr)-1]
	}
}
func solve() {
	var arr = []int{}
	combination(0, -1, arr)
}
func main() {
	defer writer.Flush()
	// f, err := os.Open("./15686.txt")
	// if err != nil {
	// 	fmt.Println(err)
	// }
	// defer f.Close()
	reader = bufio.NewReader(os.Stdin)

	input()
	solve()
	fmt.Fprint(writer, res)
}
