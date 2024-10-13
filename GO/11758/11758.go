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

type Pos struct {
	x int
	y int
}

type Line struct {
	pos []Pos
}

func input(io *IO) *Line {
	var line Line
	var x, y int

	// line.pos = make([]Pos, 0)
	for i := 1; i < 4; i++ {
		fmt.Fscan(io.reader, &x, &y)
		line.pos = append(line.pos, Pos{x, y})
	}
	return &line
}

func solve(line *Line) int {

	return ccw(line.pos[0], line.pos[1], line.pos[2])
}

func ccw(a, b, c Pos) int {
	val := (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x)

	if val > 0 {
		return 1 // 반시계 방향
	} else if val < 0 {
		return -1 // 시계 방향
	} else {
		return 0 // 일직선
	}
}

func main() {
	// f, _ := os.Open("./11758.txt")
	// defer f.Close()

	io := &IO{bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)}
	defer io.writer.Flush()

	line := input(io)
	res := solve(line)
	fmt.Fprint(io.writer, res)
}
