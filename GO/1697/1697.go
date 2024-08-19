package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)
var N, K int
var arr = make([]int, 100001)
var d = [3]int{1, -1, 2}

func main() {
	defer writer.Flush()
	reader = bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N, &K)

	for i := range arr {
		arr[i] = 100001
	}

	que := []int{N}
	arr[N] = 0
	for len(que) > 0 {
		el := que[0]
		que = que[1:]

		for i := 0; i < 3; i++ {
			var nd int
			if i == 2 {
				nd = el * d[i]
			} else {
				nd = el + d[i]
			}

			if nd >= 0 && nd <= 100000 && arr[el]+1 < arr[nd] {
				arr[nd] = arr[el] + 1
				que = append(que, nd)
			}
		}
	}
	fmt.Fprint(writer, arr[K])
}
