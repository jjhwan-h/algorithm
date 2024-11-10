package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader  = bufio.NewReader(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	vNum, N int
	dp      [41]int
)

func sit(m int) int {
	if dp[m] != 0 {
		return dp[m]
	}
	dp[m] = sit(m-1) + sit(m-2)
	return dp[m]
}

func input() []int {
	var vip int
	fmt.Fscan(reader, &N, &vNum)

	VIPs := make([]int, vNum+1)
	for i := 1; i <= vNum; i++ {
		fmt.Fscan(reader, &vip)
		VIPs[i] = vip
	}
	return VIPs
}

func solve(VIPs []int) {
	res := 1
	dp[0] = 1 //res를 1로 유지
	dp[1] = 1
	dp[2] = 2
	for j := 1; j <= vNum; j++ {
		res *= sit(VIPs[j] - VIPs[j-1] - 1)
	}
	res *= sit(N - VIPs[vNum])
	fmt.Fprint(writer, res)
}

func main() {
	defer writer.Flush()

	// f, _ := os.Open("./2302.txt")
	// defer f.Close()
	// reader = bufio.NewReader(f)

	VIPs := input()
	solve(VIPs)
}
