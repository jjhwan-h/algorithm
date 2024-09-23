package main

import (
	"bufio"
	"fmt"
	"os"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}
type Table struct {
	table [100001][3]int
}
type Score struct {
	table [2][100001][3]int // 0:최대, 1:최소
}

var N int

func input(io IO) *Table {
	var a, b, c int
	t := Table{}

	fmt.Fscan(io.reader, &N)
	for i := 0; i < N; i++ {
		fmt.Fscan(io.reader, &a, &b, &c)
		t.table[i][0] = a
		t.table[i][1] = b
		t.table[i][2] = c
	}
	return &t
}
func solve(io IO, t *Table) {
	var tmp int
	s := Score{}
	s.table[0][0] = t.table[0]
	s.table[1][0] = t.table[0]

	for i := 1; i < N; i++ {
		tmp = s.table[0][i-1][0]
		for j := 0; j < 2; j++ {
			if tmp < s.table[0][i-1][j+1] {
				s.table[0][i][j] = s.table[0][i-1][j+1] + t.table[i][j]
				tmp = s.table[0][i-1][j+1]
			} else {
				s.table[0][i][j] = tmp + t.table[i][j]
			}
		}
		if s.table[0][i-1][1] < s.table[0][i-1][2] {
			tmp = s.table[0][i-1][2]
		} else {
			tmp = s.table[0][i-1][1]
		}
		s.table[0][i][2] = tmp + t.table[i][2]

		tmp = s.table[1][i-1][0]
		for j := 0; j < 2; j++ {
			if tmp < s.table[1][i-1][j+1] {
				s.table[1][i][j] = tmp + t.table[i][j]
			} else {
				s.table[1][i][j] = s.table[1][i-1][j+1] + t.table[i][j]
				tmp = s.table[1][i-1][j+1]
			}
		}
		if s.table[1][i-1][1] < s.table[1][i-1][2] {
			tmp = s.table[1][i-1][1]
		} else {
			tmp = s.table[1][i-1][2]
		}
		s.table[1][i][2] = tmp + t.table[i][2]
	}

	num1 := s.table[0][N-1][0]
	num2 := s.table[1][N-1][0]
	for i := 1; i < 3; i++ {
		if num1 < s.table[0][N-1][i] {
			num1 = s.table[0][N-1][i]
		}
		if num2 > s.table[1][N-1][i] {
			num2 = s.table[1][N-1][i]
		}
	}
	fmt.Fprint(io.writer, num1, num2)

}
func main() {
	// f, _ := os.Open("./2096.txt")
	// defer f.Close()
	io := IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	t := input(io)
	solve(io, t)
}
