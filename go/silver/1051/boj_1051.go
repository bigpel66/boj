package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type coord struct {
	X int
	Y int
}

type Data struct {
	R      *bufio.Reader
	W      *bufio.Writer
	Answer int
	Tile   []string
	coord
}

func inputAction() *Data {
	d := &Data{}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.X, &d.Y)
	d.Tile = make([]string, d.X)
	for i := 0; i < d.X; i++ {
		fmt.Fscan(d.R, &d.Tile[i])
	}
	return d
}

func Solution(d *Data) {
	side := int(math.Min(float64(d.X), float64(d.Y)))
	for i := 0; i < d.X; i++ {
		for j := 0; j < d.Y; j++ {
			for k := 0; k < side; k++ {
				if i+k >= d.X || j+k >= d.Y {
					break
				}
				if d.Tile[i][j] != d.Tile[i+k][j] ||
					d.Tile[i][j] != d.Tile[i][j+k] ||
					d.Tile[i][j] != d.Tile[i+k][j+k] {
					continue
				}
				if d.Answer < k {
					d.Answer = k
				}
			}
		}
	}
	d.Answer = (d.Answer + 1) * (d.Answer + 1)
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
