package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var unf = make([]int, 1001)
var res = make([]int, 1001)

func FIND(a int) int {
	if a == unf[a] {
		return a
	}
	unf[a] = FIND(unf[a])
	return unf[a]
}
func UNION(a, b int) {
	fa := FIND(a)
	fb := FIND(b)
	if fa != fb {
		unf[fa] = fb
	}
}
func main() {
	var cnt int
	defer writer.Flush()

	// file, err := os.Open("./11724.txt")
	// if err != nil {
	// 	fmt.Println("can'not open file", err)
	// }
	// defer file.Close()

	reader = bufio.NewReader(os.Stdin)

	var N, M, s, e int
	fmt.Fscan(reader, &N, &M)

	for i := 1; i <= N; i++ {
		unf[i] = i
	}
	for i := 0; i < M; i++ {
		fmt.Fscan(reader, &s, &e)
		UNION(s, e)
	}
	for i := 1; i <= N; i++ {
		if res[FIND(i)] == 0 {
			cnt++
			res[FIND(i)] = res[FIND(i)] + 1
		}
	}
	fmt.Fprint(writer, cnt)
}
