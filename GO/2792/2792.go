package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	scanner                = bufio.NewScanner(os.Stdin)
	writer                 = bufio.NewWriter(os.Stdout)
	N, M, left, right, res int
)

func main() {
	scanner.Split(bufio.ScanWords)
	defer writer.Flush()

	N, M = ScanInt(), ScanInt()
	arr := make([]int, M)
	for i := range M {
		arr[i] = ScanInt()
		if right < arr[i] {
			right = arr[i]
		}
	}

	left, res = 1, math.MaxInt32
	var mid int
	for left <= right {
		mid = (left + right) / 2
		if isPossibleNum(mid, arr) {
			if res > mid {
				res = mid
			}
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	fmt.Fprintln(writer, res)
}

func isPossibleNum(mid int, arr []int) bool {
	var n, mod int
	for _, val := range arr {
		n += val / mid
		mod = val % mid
		if mod > 0 {
			n += 1
		}
	}
	return n <= N
}

func ScanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
