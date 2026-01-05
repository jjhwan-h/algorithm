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
	block   = make([]int, 10001)
)

func main() {
	f, _ := os.OpenFile("./2564.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	x, y, n := scanInt(), scanInt(), scanInt()

	for i := range n {
		dir, offset := scanInt(), scanInt()
		block[i] = getOffset(x, y, dir, offset)
	}
	ddir, doffset := scanInt(), scanInt()
	dOffset := getOffset(x, y, ddir, doffset)

	res := 0
	for i := range n {
		tmp := int(math.Abs(float64(dOffset - block[i])))
		res += min(tmp, 2*x+2*y-tmp)
	}
	fmt.Fprintln(writer, res)
}

func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func getOffset(x, y, dir, offset int) (newOffset int) {
	switch dir {
	case 1:
		newOffset = offset
	case 2:
		newOffset = x + y + x - offset
	case 3:
		newOffset = x + y + x + y - offset
	case 4:
		newOffset = x + offset
	}
	return
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
