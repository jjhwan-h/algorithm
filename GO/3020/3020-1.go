package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader *bufio.Scanner
	writer = bufio.NewWriter(os.Stdout)
	N, H   int
)

type Obst struct {
	top  [500001]int
	down [500001]int
}

func setup() *Obst {
	N, H = readInt(), readInt()
	obst := &Obst{}
	for i := 1; i <= N; i++ {
		tmp := readInt()
		if i%2 == 0 {
			obst.top[H-tmp+1] += 1
		} else {
			obst.down[tmp] += 1
		}
	}

	for j := H - 1; j >= 1; j-- {
		obst.down[j] += obst.down[j+1]
	}
	return obst
}

func solve(obst *Obst) {
	min, cnt := 200001, 0
	for i := 1; i <= H; i++ {
		obst.top[i] += obst.top[i-1]
		res := obst.down[i] + obst.top[i]
		if min > res {
			min = res
			cnt = 1
		} else if min == res {
			cnt++
		}
	}
	fmt.Fprint(writer, min, cnt)
}

func main() {
	defer writer.Flush()
	f, _ := os.Open("./3020.txt")
	defer f.Close()

	reader = bufio.NewScanner(f)
	reader.Split(bufio.ScanWords)

	obst := setup()
	solve(obst)
}

func parseInt(s string) int {
	n, _ := strconv.Atoi(s)
	return n
}

func readInt() int {
	reader.Scan()
	return parseInt(reader.Text())
}
