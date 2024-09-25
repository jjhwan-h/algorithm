package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

var (
	hasZero bool
)

func input(io *IO) []int {
	hasZero = false
	var num, N int
	fmt.Fscan(io.reader, &N)
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(io.reader, &num)
		if num == 0 {
			hasZero = true
			continue
		}
		arr[i] = num
	}
	return arr
}
func solve(arr []int) int {
	res := 0
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	tmp, cnt := 0, 1
	for i := 0; i < len(arr) && arr[i] < 0; i++ {
		if cnt%2 == 0 {
			res += tmp * arr[i]
		} else {
			tmp = arr[i]
		}
		cnt++
	}
	if !hasZero && (cnt-1)%2 != 0 {
		res += tmp
	}

	cnt = 1
	for i := len(arr) - 1; i >= 0 && arr[i] > 0; i-- {
		if cnt%2 == 0 {
			if tmp == 1 || arr[i] == 1 {
				res += tmp + arr[i]
			} else {
				res += tmp * arr[i]
			}
		} else {
			tmp = arr[i]
		}
		cnt++
	}
	if (cnt-1)%2 != 0 {
		res += tmp
	}

	return res
}

func main() {
	// f, _ := os.Open("./2036.txt")
	// defer f.Close()

	io := IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	arr := input(&io)
	res := solve(arr)
	fmt.Fprint(io.writer, res)
}

/*
	0이 있는 경우
		음수개수가 홀수인경우
			+가장 큰 음수 * 0
		음수개수가 짝수인경우
			+0
		양수개수가 홀수인경우
			+가장 작은 양수
		양수개수가 짝수인경우
			+

	0이 없는 경우
		음수개수가 홀수인경우
			+가장 큰 음수
		음수개수가 짝수인경우
			+
		양수개수가 홀수인경우
			+가장 작은 양수
		양수개수가 짝수인경우
			+

	단 양수 2개씩 짝지었을때 둘 중 1이 포함된경우는
		두 수를 더한다.
*/
