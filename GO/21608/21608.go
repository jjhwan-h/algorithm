package main

import (
	"bufio"
	"fmt"
	"os"
)

type (
	IOHandler struct {
		reader *bufio.Reader
		writer *bufio.Writer
	}
	Student struct {
		order    []int
		favorite [][4]int
	}
)

var (
	N     int
	L     int
	Graph [20][20]int
	dir   = [4][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
)

func input(reader *bufio.Reader) Student {
	fmt.Fscan(reader, &N)
	L = N * N
	students := Student{make([]int, L+1), make([][4]int, L+1)}
	for i := 0; i < L; i++ {
		var s, t int
		fmt.Fscan(reader, &s)
		students.order[i] = s
		for j := 0; j < 4; j++ {
			fmt.Fscan(reader, &t)
			students.favorite[s][j] = t
		}
	}
	return students
}
func findFavorite(find int, favorite [4]int) bool {
	for _, s := range favorite {
		if find == s {
			return true
		}
	}
	return false
}
func searchGraph(favorite [4]int) [2]int {
	coordi := [2]int{-1, -1}
	fCnt, eCnt := -1, -1 //좋아하는 학생 count, 인접한 비어있는 칸 count

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if Graph[i][j] != 0 {
				continue
			}
			f, e := 0, 0
			for k := 0; k < 4; k++ {
				dy := i + dir[k][0]
				dx := j + dir[k][1]
				if dy >= 0 && dy < N && dx >= 0 && dx < N {
					if Graph[dy][dx] != 0 && findFavorite(Graph[dy][dx], favorite) {
						f++
					} else if Graph[dy][dx] == 0 {
						e++
					}
				}
			}

			if fCnt < f {
				coordi = [2]int{i, j}
				fCnt = f
				eCnt = e
			} else if fCnt == f {
				if eCnt < e {
					coordi = [2]int{i, j}
					eCnt = e
				}
			}
		}
	}
	return coordi
}
func getSatisfaction(favorite [][4]int) int {
	cnt := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			flag := false
			exp := 1
			for k := 0; k < 4; k++ {
				dy := i + dir[k][0]
				dx := j + dir[k][1]
				if dy >= 0 && dy < N && dx >= 0 && dx < N {
					if findFavorite(Graph[dy][dx], favorite[Graph[i][j]]) {
						exp *= 10
						flag = true
					}
				}
			}
			if flag {
				cnt += exp / 10
			}
		}
	}
	return cnt
}
func solve(students Student, writer *bufio.Writer) {
	for i := 0; i < L; i++ {
		coordi := searchGraph(students.favorite[students.order[i]])
		Graph[coordi[0]][coordi[1]] = students.order[i]
	}
	res := getSatisfaction(students.favorite)
	fmt.Fprint(writer, res)
}
func main() {
	// f, _ := os.Open("./21608.txt")
	// defer f.Close()
	ioHandler := IOHandler{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	defer ioHandler.writer.Flush()

	students := input(ioHandler.reader)
	solve(students, ioHandler.writer)
}
