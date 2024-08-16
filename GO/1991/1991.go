package main

import (
	"bufio"
	"fmt"
	"os"
)

type node struct {
	n  rune
	lc rune
	rc rune
}
type nodeSlice []node

var nodes = make(nodeSlice, 27)
var reader *bufio.Reader
var writer = bufio.NewWriter(os.Stdout)

func input() {
	var num int
	var n, l, r rune
	fmt.Fscanf(reader, "%d\n", &num)

	for i := 0; i < num; i++ {
		fmt.Fscanf(reader, "%c %c %c\n", &n, &l, &r)
		nodes[int(n)-'A'] = node{n, l, r}
	}
}
func (p nodeSlice) prefix(idx int) {
	if idx < 0 {
		return
	}
	fmt.Fprintf(writer, "%c", p[idx].n)
	p.prefix(int(p[idx].lc) - 'A')
	p.prefix(int(p[idx].rc) - 'A')
}
func (p nodeSlice) postfix(idx int) {
	if idx < 0 {
		return
	}
	p.postfix(int(p[idx].lc) - 'A')
	p.postfix(int(p[idx].rc) - 'A')
	fmt.Fprintf(writer, "%c", p[idx].n)
}
func (p nodeSlice) infix(idx int) {
	if idx < 0 {
		return
	}
	p.infix(int(p[idx].lc) - 'A')
	fmt.Fprintf(writer, "%c", p[idx].n)
	p.infix(int(p[idx].rc) - 'A')
}
func solve() {
	nodes.prefix(0)
	fmt.Fprint(writer, "\n")
	nodes.infix(0)
	fmt.Fprint(writer, "\n")
	nodes.postfix(0)
}
func main() {
	defer writer.Flush()

	// file, err := os.Open("./1991.txt")
	// if err != nil {
	// 	fmt.Println("can'not open file", err)
	// }
	// defer file.Close()
	reader = bufio.NewReader(os.Stdin)

	input()
	solve()
}
