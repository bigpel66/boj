package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// (x, y) 기준으로 x가 작은 순서대로 정렬
// (x1, y1)을 기준으로 로직을 수행할 때, 그 다음 점을 (x2, y2)라고 가정 (leftPoint는 x1, rightPoint는 y1)
// 만일 두 점이 겹치는 상태라면, 기존 rightPoint와 새로운 점의 y2 비교에 따라 rightPoint를 갱신
// 두 점이 겹치지 않는 점이라면, 기존의 rightPoint - leftPoint를 길이에 누적 후 leftPoint와 rightPoint 갱신

type Line struct {
	BeginPosition int // 시작점
	EndPosition   int // 끝점
}

type Data struct {
	R            *bufio.Reader
	W            *bufio.Writer
	Answer       int    // 정답
	NumberOfLine int    // 라인의 수
	Lines        []Line // 라인 정보들
}

func inputAction() *Data {
	d := &Data{Lines: []Line{}}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.NumberOfLine)
	for i := 0; i < d.NumberOfLine; i++ {
		line := Line{}
		fmt.Fscan(d.R, &line.BeginPosition, &line.EndPosition)
		d.Lines = append(d.Lines, line)
	}
	return d
}

func maxInt(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func measureLength(d *Data) {
	leftPoint := -int(^uint(0)>>1) - 1
	rightPoint := -int(^uint(0)>>1) - 1
	for i := 0; i < d.NumberOfLine; i++ {
		if rightPoint >= d.Lines[i].BeginPosition {
			rightPoint = maxInt(rightPoint, d.Lines[i].EndPosition)
		} else {
			d.Answer += rightPoint - leftPoint
			leftPoint = d.Lines[i].BeginPosition
			rightPoint = d.Lines[i].EndPosition
		}
	}
	d.Answer += rightPoint - leftPoint
}

func Solution(d *Data) {
	compareLines := func(i, j int) bool {
		return d.Lines[i].BeginPosition < d.Lines[j].BeginPosition
	}
	sort.Slice(d.Lines, compareLines)
	measureLength(d)
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
