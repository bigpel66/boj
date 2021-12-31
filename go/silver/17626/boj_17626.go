package main

import (
	"bufio"
	"fmt"
	"os"
)

type Data struct {
	R      *bufio.Reader
	W      *bufio.Writer
	Value  int
	Memoi  []int
	Answer int
}

func inputAction() *Data {
	d := &Data{}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.Value)
	d.Memoi = make([]int, d.Value+1)
	d.Memoi[1] = 1
	return d
}

func Solution(d *Data) {
	for i := 2; i <= d.Value; i++ {
		min := int(^uint(0) >> 1)
		for j := 1; j*j <= i; j++ {
			diff := i - j*j
			if min > d.Memoi[diff] {
				min = d.Memoi[diff]
			}
		}
		d.Memoi[i] = min + 1
	}
	d.Answer = d.Memoi[d.Value]
}

func outputAction(d *Data) {
	fmt.Fprint(d.W, d.Answer)
}

func main() {
	d := inputAction()
	defer d.W.Flush()
	Solution(d)
	outputAction(d)
}
