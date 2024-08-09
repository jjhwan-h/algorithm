package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func main() {
	defer writer.Flush()

	bytes, _, _ := reader.ReadLine()
	line := string(bytes)
	nums := strings.Fields(line)
	a, _ := strconv.Atoi(nums[0])

	arr := make([]int, a+1)

	for i := 2; i < len(arr); i++ {
		arr[i] = arr[i-1] + 1
		if i%2 == 0 {
			if arr[i] > arr[i/2]+1 {
				arr[i] = arr[i/2] + 1
			}
		}
		if i%3 == 0 {
			if arr[i] > arr[i/3]+1 {
				arr[i] = arr[i/3] + 1
			}
		}
	}
	writer.WriteString(strconv.Itoa(arr[a]))
}
