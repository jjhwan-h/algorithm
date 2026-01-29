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
	dp      = make([][11]int, 65)
)

func main() {
	f, _ := os.OpenFile("./2688.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	for i := range 10 {
		dp[1][i] = 1
		dp[1][10] += dp[1][i]
	}

	maxDigit := 1
	N := scanInt()
	for range N {
		d := scanInt()
		if d > maxDigit {
			for i := maxDigit + 1; i <= d; i++ {
				dp[i][0] = dp[i-1][10]
				dp[i][10] = dp[i][0]
				for j := 1; j < 10; j++ {
					dp[i][j] = dp[i][j-1] - dp[i-1][j-1]
					dp[i][10] += dp[i][j]
				}
			}
			maxDigit = d
		}
		fmt.Fprintf(writer, "%d\n", dp[d][10])
	}
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
