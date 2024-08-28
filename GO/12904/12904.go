package main

import (
	"bufio"
	"fmt"
	"os"
)

var S, T, reverseS string

func input(reader *bufio.Reader) {
	fmt.Fscan(reader, &S)
	fmt.Fscan(reader, &T)
}
func isMatch(isReverse bool) bool {
	if isReverse {
		if reverseS == T {
			return true
		}
	} else {
		if T == S {
			return true
		}
	}
	return false
}
func solve() int {
	isReverse := false
	for i := len(S) - 1; i >= 0; i-- {
		reverseS = reverseS + string(S[i])
	}

	for i := len(T) - 1; i >= 0; i-- {
		if len(T) < len(S) {
			return 0
		}

		if isMatch(isReverse) {
			return 1
		}

		var idx int
		if isReverse {
			idx = 0
		} else {
			idx = i
		}

		if T[idx] == 'A' {
			if isReverse {
				T = T[idx+1:]
			} else {
				T = T[:idx]
			}
		} else if T[idx] == 'B' {
			if isReverse {
				T = T[idx+1:]
				isReverse = false
			} else {
				T = T[:idx]
				isReverse = true
			}
		}
	}
	return 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	input(reader)
	res := solve()
	fmt.Fprint(writer, res)
}
