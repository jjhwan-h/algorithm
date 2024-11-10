package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	stage  [2001][2001]int
)

func gcd(i, j int) int {
	for j%i != 0 {
		j, i = i, j%i
	}
	return i
}

/*
func gcd(a,b int)int{ (a>b)
	if b==0{
		return a
	}
	return gcd(b,a%b)
}
*/

func solve() {
	var d1, d2, res int
	fmt.Fscan(reader, &d1, &d2)

	for i := d1; i <= d2; i++ {
		for j := 1; j <= i; j++ {
			t := gcd(j, i)
			num, deno := j/t, i/t
			if stage[num][deno] == 0 {
				stage[num][deno] = 1
				res++
			}
		}
	}
	fmt.Fprintln(writer, res)
}

func main() {
	defer writer.Flush()

	solve()
}
