package main

import (
	"bufio"
	"math"
	"os"
	"strconv"
	"strings"
)

type Circle interface {
	isUpon() int
}

type pos struct {
	x, y, r float64
}

var N int

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	bytes, _, _ := reader.ReadLine()
	line := string(bytes)
	N, _ = strconv.Atoi(line)

	var x1, y1, r1, x2, y2, r2 float64
	for i := 0; i < N; i++ {
		bytes, _, _ := reader.ReadLine()
		line := string(bytes)
		nums := strings.Fields(line)
		x1, _ = strconv.ParseFloat(nums[0], 64)
		y1, _ = strconv.ParseFloat(nums[1], 64)
		r1, _ = strconv.ParseFloat(nums[2], 64)
		x2, _ = strconv.ParseFloat(nums[3], 64)
		y2, _ = strconv.ParseFloat(nums[4], 64)
		r2, _ = strconv.ParseFloat(nums[5], 64)

		var p1 = pos{x1, y1, r1}
		var p2 = pos{x2, y2, r2}
		res := p1.isUpon(p2)

		writer.WriteString(strconv.Itoa(res) + "\n")
	}
}

func (p1 pos) isUpon(p2 pos) int {
	var dist1 = math.Sqrt(math.Pow((p1.x-p2.x), 2) + math.Pow((p1.y-p2.y), 2))
	var dist2 = math.Abs(p2.r + p1.r)

	if dist1+p1.r <= p2.r || dist1+p2.r <= p1.r {
		if p1.r == p2.r {
			return -1
		} else if dist1+p1.r == p2.r || dist1+p2.r == p1.r {
			return 1
		} else {
			return 0
		}
	} else {
		if dist1 == dist2 {
			return 1
		} else if dist2 > dist1 {
			return 2
		} else {
			return 0
		}
	}
}
