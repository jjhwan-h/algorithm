package main

import (
	"fmt"
)

var N int
var cnt int = 0

func main() {
	fmt.Scan(&N)
	if N < 100 {
		cnt = N
	} else {
		cnt = 99
		for i := 100; i <= N; i++ {
			flag := true
			arr := []int{}
			num := i
			for num > 0 {
				digit := num % 10
				arr = append(arr, digit)
				num = num / 10
			}

			diff := arr[1] - arr[0]
			for j := 2; j < len(arr); j++ {
				if diff != arr[j]-arr[j-1] {
					flag = false
					break
				}
			}
			if flag {
				cnt++
			}

		}
	}
	fmt.Print(cnt)
}
