package main

import (
	"bufio"
	"fmt"
	"os"
)

type Data struct {
	R       *bufio.Reader
	W       *bufio.Writer
	Day     int
	Number  int
	Answer1 int
	Answer2 int
	CoefA   []int
	CoefB   []int
}

func inputAction() *Data {
	d := &Data{}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.Day, &d.Number)
	d.CoefA = make([]int, d.Day+1)
	d.CoefB = make([]int, d.Day+1)
	d.CoefA[1] = 1
	d.CoefB[2] = 1
	return d
}

func Solution(d *Data) {
	for i := 3; i <= d.Day; i++ {
		d.CoefA[i] = d.CoefA[i-1] + d.CoefA[i-2]
		d.CoefB[i] = d.CoefB[i-1] + d.CoefB[i-2]
	}
	for i := 1; i <= d.Number; i++ {
		if (d.Number-d.CoefA[d.Day]*i)%d.CoefB[d.Day] == 0 {
			d.Answer1 = i
			d.Answer2 = (d.Number - d.CoefA[d.Day]*i) / d.CoefB[d.Day]
			return
		}
	}
}

func outputAction(d *Data) {
	fmt.Fprintln(d.W, d.Answer1)
	fmt.Fprintln(d.W, d.Answer2)
}

func main() {
	d := inputAction()
	defer d.W.Flush()
	Solution(d)
	outputAction(d)
}
