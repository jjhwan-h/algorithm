package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin) // 입력이 큰경우는 reader로 가는게 유리
	writer = bufio.NewWriter(os.Stdout)
	N      int
)

func main() {
	f, _ := os.OpenFile("./17615.txt", os.O_RDONLY, 0644)
	defer f.Close()
	reader = bufio.NewReader(f)

	defer writer.Flush()

	fmt.Fscan(reader, &N)
	balls := make([]byte, 0, N)
	reader.ReadBytes('\n')
	for {
		line, isPrefix, err := reader.ReadLine()
		balls = append(balls, line...)
		if !isPrefix || err != nil {
			break
		}
	}

	res := math.MaxInt32
	l := len(balls)
	for _, color := range []rune{'B', 'R'} {
		res = smallerInt(res, toRight(balls, l, color))
		res = smallerInt(res, toLeft(balls, l, color))
	}

	fmt.Fprintln(writer, res)
}

func toRight(balls []byte, length int, target rune) int {
	cnt := 0
	flag := false
	for i := 0; i < length; i++ {
		if balls[i] != byte(target) {
			flag = true
		} else if flag {
			cnt++
		}
	}
	return cnt
}

func toLeft(balls []byte, length int, target rune) int {
	cnt := 0
	flag := false
	for j := length - 1; j >= 0; j-- {
		if balls[j] != byte(target) {
			flag = true
		} else if flag {
			cnt++
		}
	}
	return cnt
}

func smallerInt(a, b int) int {
	if a > b {
		return b
	}
	return a
}
