package main

import (
	"bufio"
	"fmt"
	"os"
)

type Friends struct {
	N       int
	arr     [2001][]int
	visited [2001]int
}

// func NewFriends(num int) Friends {
// 	f := Friends{make([][]int, num)}
// 	for i := range f.arr {
// 		f.arr[i] = make([]int, num)
// 	}
// 	return f
// }

func Input(reader *bufio.Reader) Friends {
	var N, M, s, e int
	fmt.Fscan(reader, &N, &M)
	f := Friends{}
	f.N = N
	for i := 0; i < M; i++ {
		fmt.Fscan(reader, &s, &e)
		f.arr[s] = append(f.arr[s], e)
		f.arr[e] = append(f.arr[e], s)
	}
	return f
}

func (f *Friends) Search(a int, cnt int) int {
	if cnt == 4 {
		return 1
	}
	for i := 0; i < len(f.arr[a]); i++ {
		if f.visited[f.arr[a][i]] != 1 {
			//fmt.Print(strconv.Itoa(a), strconv.Itoa(f.arr[a][i]), strconv.Itoa(cnt)+"\n")
			f.visited[f.arr[a][i]] = 1
			res := f.Search(f.arr[a][i], cnt+1)
			if res == 1 {
				return 1
			}
			f.visited[f.arr[a][i]] = 0
		}
	}
	return 0
}

func Solve(f Friends) int {
	for i := 0; i < f.N; i++ {
		f.visited[i] = 1
		res := f.Search(i, 0)
		f.visited[i] = 0
		if res == 1 {
			return 1
		}
	}
	return 0
}

func main() {
	f, _ := os.Open("./13023.txt")
	defer f.Close()

	reader := bufio.NewReader(f)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	friends := Input(reader)
	res := Solve(friends)
	fmt.Fprint(writer, res)
}
