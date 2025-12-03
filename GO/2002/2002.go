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

	f, _ := os.OpenFile("./2002.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	scanner.Split(bufio.ScanWords)

	n := ScanInt()

	m := make(map[string]int)
	input(n, m)
	res := output(n, m)

	fmt.Fprintln(writer, res)
}

func input(n int, m map[string]int) {
	for i := range n {
		s := ScanString()
		m[s] = i
	}
}

func output(n int, m map[string]int) int {
	var overtake int
	out := make([]bool, n)

	for range n {
		s := ScanString()
		j := m[s]
		out[j] = true
		for k := 0; k < j; k++ {
			if !out[k] {
				overtake++
				break
			}
		}
	}
	return overtake
}

func ScanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func ScanString() string {
	scanner.Scan()
	return scanner.Text()
}
