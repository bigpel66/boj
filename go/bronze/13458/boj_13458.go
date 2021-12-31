package main

import (
	"bufio"
	"fmt"
	"os"
)

type Info struct {
	Place  int32
	People []int32
	Main   int32
	Sub    int32
}

type Data struct {
	R      *bufio.Reader
	W      *bufio.Writer
	Answer int
	Info
}

func inputAction() *Data {
	d := new(Data)
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.Place)
	d.People = make([]int32, d.Place)
	for i := 0; i < int(d.Place); i++ {
		fmt.Fscan(d.R, &d.People[i])
	}
	fmt.Fscan(d.R, &d.Main, &d.Sub)
	d.Answer = int(d.Place)
	return d
}

func Solution(d *Data) {
	for i := 0; i < int(d.Place); i++ {
		if d.People[i] > d.Main {
			d.Answer += int((d.People[i]-d.Main-1)/d.Sub + 1)
		}
	}
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
