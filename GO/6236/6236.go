package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	N, M    int
)

func main() {
	f, _ := os.OpenFile("./6236.txt", os.O_RDONLY, 0600)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	N, M = scanInt(), scanInt()

	var maxAccount int
	var deposits []int
	for range N {
		n := scanInt()
		maxAccount += n
		deposits = append(deposits, n)
	}

	l, r, res := 1, maxAccount, math.MaxInt32
	for l <= r {
		mid := (l + r) / 2
		if isRightAmount(mid, deposits) {
			r = mid - 1
			log.Println(res)
			res = mid
		} else {
			l = mid + 1
		}
	}
	fmt.Fprint(writer, res)
}

func isRightAmount(withdraw int, deposits []int) bool {
	cnt := 1
	sum := withdraw
	for _, v := range deposits {
		if v > withdraw {
			return false
		}
		if sum < v {
			cnt++
			sum = withdraw
		}
		sum -= v
	}
	return cnt <= M
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
