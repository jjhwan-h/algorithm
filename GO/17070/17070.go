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
)

var (
	N    int
	Home [17][17]int
	dp   [17][17][3]int // 가로, 세로, 대각선
)

func NewIOHandler(reader *bufio.Reader, writer *bufio.Writer) *IOHandler {
	return &IOHandler{
		reader: reader,
		writer: writer,
	}
}

func input(reader *bufio.Reader) {
	var t int
	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Fscan(reader, &t)
			Home[i][j] = t
		}
	}
}

func solve(writer *bufio.Writer) {
	dp[0][1][0] = 1
	for i := 0; i < N; i++ {
		for j := 2; j < N; j++ {
			next := Home[i][j]
			//가로
			if j > 0 && next != 1 {
				dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
			}
			//세로
			if i > 0 && next != 1 {
				dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
			}
			//대각선
			if i > 0 && j > 0 &&
				Home[i-1][j] != 1 &&
				Home[i][j-1] != 1 &&
				next != 1 {
				dp[i][j][2] = dp[i-1][j-1][1] + dp[i-1][j-1][2] + dp[i-1][j-1][0]
			}
		}
	}
	res := dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2]
	fmt.Fprint(writer, res)
}
func main() {
	// f, _ := os.Open("./17070.txt")
	// defer f.Close()

	ioHandler := NewIOHandler(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	defer ioHandler.writer.Flush()

	input(ioHandler.reader)
	solve(ioHandler.writer)
}
