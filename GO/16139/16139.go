package main

import (
	"bufio"
	"fmt"
	"os"
)

const ALPHABET = 27

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	sumArr = make([][200_001]int, ALPHABET)
)

func main() {
	defer writer.Flush()
	accumulateStr()
	run()
}

func run() {
	var (
		N, l, r int
		s       string
	)
	fmt.Fscan(reader, &N)

	for range N {
		fmt.Fscan(reader, &s, &l, &r)
		find := int([]rune(s)[0])
		lleft := sumArr[find-'a'][l]
		left := sumArr[find-'a'][l+1]
		right := sumArr[find-'a'][r+1]

		res := right - left
		if lleft != left {
			res++
		}

		fmt.Fprintf(writer, "%d\n", res)
	}
}

func accumulateStr() {
	var str string
	fmt.Fscan(reader, &str)

	for i, s := range str {
		ascii := int(s)
		for j := range sumArr {
			if ascii-'a' == j {
				sumArr[j][i+1] = sumArr[j][i] + 1
				continue
			}
			sumArr[j][i+1] = sumArr[j][i]
		}
	}
}
