package main

import (
	"bufio"
	"fmt"
	"os"
)

type Data struct {
	R            *bufio.Reader
	W            *bufio.Writer
	Participants int
	Kim          int
	Lim          int
	Answer       int
}

func inputAction() *Data {
	d := &Data{}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.Participants, &d.Kim, &d.Lim)
	return d
}

func Solution(d *Data) {
	count := 0
	for {
		count++
		d.Kim = (d.Kim + 1) / 2
		d.Lim = (d.Lim + 1) / 2
		if d.Kim == d.Lim {
			break
		}
	}
	d.Answer = count
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
