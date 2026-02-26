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

type beads []int

func main() {
	f, _ := os.OpenFile("./16198.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	n := scanInt()
	beads := make(beads, n)

	for idx := range beads {
		beads[idx] = scanInt()
	}

	fmt.Fprintln(writer, run(beads, 0))
}

func run(b beads, energy int) int {
	if len(b) == 2 {
		return energy
	}
	if len(b) == 3 {
		return energy + b[0]*b[2]
	}

	res := 0
	for i := 1; i < len(b)-1; i++ {
		dst := make(beads, len(b))
		copy(dst, b)

		ee, newb := pop(dst, i-1, i+1)
		sumEnergy := run(newb, ee+energy)
		if res < sumEnergy {
			res = sumEnergy
		}
	}
	return res
}

func pop(b beads, l, r int) (int, []int) {
	multi := b[l] * b[r]
	nb := append(b[:l+1], b[r:]...)
	return multi, nb
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
