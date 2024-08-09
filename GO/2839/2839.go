package main

import "fmt"

var pb = []int{3, 5}

func initial(dp []int) {
	for idx := range dp {
		dp[idx] = 5001
	}
	dp[0] = 0
}
func main() {
	var N int
	fmt.Scanf("%d", &N)

	var dp = make([]int, N+1)
	initial(dp)
	for _, v := range pb {
		for j := v; j <= N; j++ {
			if dp[j] > dp[j-v]+1 {
				dp[j] = dp[j-v] + 1
			}
		}
	}

	if dp[N] == 5001 {
		fmt.Print("-1")
	} else {
		fmt.Print(dp[N])
	}
}
