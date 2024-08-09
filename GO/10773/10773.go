package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, sum int
	arr := make([]int, 0)
	fmt.Fscan(reader, &N)

	for i := 0; i < N; i++ {
		var num int
		fmt.Fscan(reader, &num)
		if num == 0 {
			temp := arr[:len(arr)-1]
			arr = temp
		} else {
			arr = append(arr, num)
		}
	}

	for i := 0; i < len(arr); i++ {
		sum += arr[i]
	}
	fmt.Fprint(writer, sum)
}
