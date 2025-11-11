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
)

func main() {
	defer writer.Flush()

	scanner.Split(bufio.ScanWords)
	N, K := ScanInt(), ScanInt()

	seq := make([]int, N)
	for i := range N {
		seq[i] = ScanInt()
	}

	res := getLongestPartialSeq(seq, K)
	fmt.Fprint(writer, res)
}

func getLongestPartialSeq(seq []int, limit int) int {
	var L int
	arr := make([]int, 100_001)
	for p1, p2 := 0, 0; p2 < len(seq); p2++ {
		for arr[seq[p2]] >= limit {
			arr[seq[p1]]--
			p1++
		}

		arr[seq[p2]]++
		if p2-p1 > L {
			L = p2 - p1
		}
	}

	return L + 1
}

func ScanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
