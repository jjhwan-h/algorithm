package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

func main() {
	f, _ := os.OpenFile("./1105.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	L, R := scanString(), scanString()
	fmt.Fprintln(writer, solve(L, R))
}

func solve(l, r string) int {
	// (1) L,R이 같은경우
	if l == r {
		return strings.Count(l, "8")
	}
	// (2) L,R의 자릿수가 같은 경우
	if len(l) == len(r) {
		cnt := 0
		for idx := range l {
			if l[idx] == r[idx] {
				if l[idx] == '8' {
					cnt++
				}
			} else {
				break
			}
		}
		return cnt
	}
	// (3) L,R의 자릿수가 다른 경우
	return 0
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}
