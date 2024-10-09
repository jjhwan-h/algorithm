package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	cnt [5001]int
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func input(io *IO) []int {
	var str string
	var password []int
	fmt.Fscan(io.reader, &str)

	parts := strings.Split(str, "")
	for _, val := range parts {
		num, _ := strconv.Atoi(val)
		password = append(password, num)
	}
	for idx, val := range password {
		if idx == 0 && val == 0 {
			return []int{}
		}
		if val == 0 && (password[idx-1] != 1 && password[idx-1] != 2) {
			return []int{}
		}
	}
	return password
}

func DFS(i int, password []int) int {
	if i == len(password) {
		return 1
	}

	if cnt[i] != 0 {
		return cnt[i]
	}

	if password[i] > 0 {
		cnt[i] %= 1000000
		cnt[i] += DFS(i+1, password)
		if i < len(password)-1 {
			num := password[i]*10 + password[i+1]
			if num < 27 && num > 0 {
				cnt[i] %= 1000000
				cnt[i] += DFS(i+2, password)
			}
		}
	}

	return cnt[i]
}

func solve(io *IO, password []int) {
	cnt[0] += DFS(1, password)
	if len(password) > 1 {
		num := password[0]*10 + password[1]
		if num < 27 {
			cnt[0] %= 1000000
			cnt[0] += DFS(2, password)
		}
	}
	cnt[0] %= 1000000
	fmt.Fprint(io.writer, cnt[0])
}

func main() {
	f, _ := os.Open("./2011.txt")
	defer f.Close()

	io := &IO{bufio.NewReader(f), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	password := input(io)
	if len(password) == 0 {
		fmt.Fprint(io.writer, 0)
		return
	}
	solve(io, password)
}
