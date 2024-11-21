package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strings"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func solve(n, k int) {
	res, base := 1, 2
	str := fmt.Sprintf("%b", n)

	if strings.Count(str, "1") <= k {
		fmt.Fprintln(writer, 0)
		return
	}

	binaryN := make([]byte, len(str))
	for i := range str {
		binaryN[i] = str[i]
	}

	for i := range binaryN {
		if binaryN[len(binaryN)-i-1] == 48 {
			if i == 0 {
				res += 1
			} else {
				res += int(math.Pow(float64(base), float64(i)))
			}
		} else { // binaryN[len(binaryN)-i-1] == 49
			cnt := 0
			for j := 0; j <= len(binaryN)-i-1; j++ {
				if cnt > k {
					break
				}
				if binaryN[j] == 49 {
					cnt++
				}
			}
			if cnt <= k {
				break
			}
		}
	}
	fmt.Fprintln(writer, res)
}

func main() {
	var n, k int
	defer writer.Flush()
	// f, _ := os.Open("./1052.txt")
	// defer f.Close()
	// reader = bufio.NewReader(f)

	fmt.Fscan(reader, &n, &k)
	solve(n, k)
}
