package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	N       int
)

func main() {
	defer writer.Flush()
	scanner.Buffer(make([]byte, 1024), 500_001) // Scanner 기본버퍼 크기는 64KB
	scanner.Split(bufio.ScanWords)

	N = scanInt()
	balls := scanString() // ball은 오직 'B' or 'R'

	res := math.MaxInt32
	l := len(balls)
	for _, color := range []rune{'B', 'R'} {
		cnt := 0
		flag := false
		for i := 0; i < l; i++ {
			if balls[i] != byte(color) {
				flag = true
			} else if flag {
				cnt++
			}
		}
		res = smallerInt(res, cnt)

		cnt = 0
		flag = false
		for j := l - 1; j >= 0; j-- {
			if balls[j] != byte(color) {
				flag = true
			} else if flag {
				cnt++
			}
		}
		res = smallerInt(res, cnt)
	}

	fmt.Fprintln(writer, res)
}

func smallerInt(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}
