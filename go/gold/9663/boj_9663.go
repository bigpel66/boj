package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type Data struct {
	R      *bufio.Reader
	W      *bufio.Writer
	Size   int
	Tile   []int
	Answer int
}

func inputAction() *Data {
	d := &Data{}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.Size)
	d.Tile = make([]int, d.Size)
	return d
}

func detection(d *Data, n int) bool {
	for i := 0; i < n; i++ {
		if d.Tile[i] == d.Tile[n] ||
			math.Abs(float64(d.Tile[n]-d.Tile[i])) == float64(n-i) {
			return false
		}
	}
	return true
}

func Solution(d *Data, n int) {
	if n == d.Size {
		d.Answer++
	} else {
		for i := 0; i < d.Size; i++ {
			d.Tile[n] = i
			if detection(d, n) {
				Solution(d, n+1)
			}
		}
	}
}

func outputAction(d *Data) {
	fmt.Fprint(d.W, d.Answer)
}

func main() {
	d := inputAction()
	defer d.W.Flush()
	Solution(d, 0)
	outputAction(d)
}
