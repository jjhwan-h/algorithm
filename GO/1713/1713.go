package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

type Candidate struct {
	num       int
	old       int
	recommend int
}

func main() {
	defer writer.Flush()

	f, _ := os.OpenFile("./1713.txt", os.O_RDONLY, 0644)
	defer f.Close()
	scanner = bufio.NewScanner(f)

	scanner.Split(bufio.ScanWords)

	n := ScanInt()
	candidates := []Candidate{}
	total := ScanInt()

	for t := range total {
		new := ScanInt()

		if idx := isExist(candidates, new); idx != -1 {
			candidates[idx].recommend++
			continue
		}

		if len(candidates) >= n {
			sort.Slice(candidates, func(i, j int) bool {
				if candidates[i].recommend == candidates[j].recommend {
					return candidates[i].old > candidates[j].old
				}
				return candidates[i].recommend > candidates[j].recommend
			})
			candidates = candidates[:len(candidates)-1]
		}
		candidates = append(candidates, Candidate{num: new, old: t, recommend: 1})
	}

	sort.Slice(candidates, func(i, j int) bool {
		return candidates[i].num < candidates[j].num
	})

	for _, c := range candidates {
		fmt.Fprintf(writer, "%d ", c.num)
	}
}

func isExist(candidates []Candidate, new int) int {
	for idx, c := range candidates {
		if c.num == new {
			return idx
		}
	}
	return -1
}

func ScanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
