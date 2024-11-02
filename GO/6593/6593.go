package main

import (
	"bufio"
	"fmt"
	"os"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

var (
	io      = &IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	L, R, C int
	dir     [6][3]int = [6][3]int{
		{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {-1, 0, 0}, {1, 0, 0},
	} //동,서,남,북,상,하
)

const (
	CUBESIZE int = 31
)

func BFS(building *[CUBESIZE][CUBESIZE][CUBESIZE]rune, queue [][4]int) (int, bool) {
	var visited [CUBESIZE][CUBESIZE][CUBESIZE]int
	min := 2147000000
	isExited := false
	for len(queue) > 0 {
		el := queue[0]
		queue = queue[1:]
		nCnt := el[3] + 1
		for i := 0; i < 6; i++ {
			nz := el[0] + dir[i][0]
			ny := el[1] + dir[i][1]
			nx := el[2] + dir[i][2]

			if nz >= 1 && nz <= L && ny >= 1 && ny <= R &&
				nx >= 1 && nx <= C && visited[nz][ny][nx] == 0 {
				if building[nz][ny][nx] == '.' {
					visited[nz][ny][nx] = 1
					queue = append(queue, [4]int{nz, ny, nx, nCnt})
				} else if building[nz][ny][nx] == 'E' {
					if min > nCnt {
						min = nCnt
						isExited = true
					}
				}
			}
		}
	}
	return min, isExited
}

func Input(building *[CUBESIZE][CUBESIZE][CUBESIZE]rune) [][4]int {
	queue := make([][4]int, 0, 10)
	var str string
	for i := 1; i <= L; i++ {
		for j := 1; j <= R; j++ {
			fmt.Fscan(io.reader, &str)
			for k, c := range str {
				(*building)[i][j][k+1] = c
				if str[k] == 'S' {
					queue = append(queue, [4]int{i, j, k + 1, 0})
				}
			}
		}
	}
	return queue
}

func Solve() {

	for {
		fmt.Fscan(io.reader, &L, &R, &C)
		if L == 0 && R == 0 && C == 0 {
			break
		}
		var building [CUBESIZE][CUBESIZE][CUBESIZE]rune
		queue := Input(&building)
		res, isExited := BFS(&building, queue)
		if isExited {
			fmt.Fprintf(io.writer, "Escaped in %d minute(s).\n", res)
		} else {
			fmt.Fprintln(io.writer, "Trapped!")
		}
	}
}

func main() {
	f, _ := os.Open("./6593.txt")
	io.reader = bufio.NewReader(f)
	defer f.Close()
	defer io.writer.Flush()
	Solve()
}

/*
슬라이스는 내부적으로 포인터, 길이, 용량을 포함하는 구조
슬라이스를 함수의 매개변수로 전달하면 실제로는 메타데이터(포인터, 길이, 용량)을 복사하여 전달
(데이터 자체를 복사하는 것이아닌, 데이터를 참조하는 포인터만 복사) => 함수내에서 슬라이스의 내용수정가능
슬라이스에 요소를 추가할 때, 내부배열의 용량이 초과된다면 새로운 배열을 생성하고 요소를 복사한다.
이 경우 원래 슬라이스(매개변수로 전달된 슬라이스의 원본)는 더 이상 새로운 슬라이스를 참조하지않으므로
따라서 원래 슬라이스를 업데이트할려면 포인터로 전달해야한다.
여기서 Input으로 넘겨줄때 'S'는 한개이므로 값으로 전달해도 괜찮다.
*/
