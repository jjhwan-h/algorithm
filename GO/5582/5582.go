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

var (
	io = &IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	dp [4000][4000]int
)

func solve() {
	var str1, str2 string
	res := 0
	fmt.Fscan(io.reader, &str1)
	fmt.Fscan(io.reader, &str2)
	for i, v1 := range str1 {
		for j, v2 := range str2 {
			if v1 == v2 {
				dp[i][j] = 1
				if i > 0 && j > 0 {
					dp[i][j] += dp[i-1][j-1]
				}
				if res < dp[i][j] {
					res = dp[i][j]
				}
			}
		}
	}
	fmt.Fprint(io.writer, res)
}

func main() {
	defer io.writer.Flush()

	// f, _ := os.Open("./5582.txt")
	// defer f.Close()
	// io.reader = bufio.NewReader(f)

	solve()
}
