package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// 동시에 진행 가능한 회의 수를 알아내야 하는 것이 문제에서 요구하는 것
// open-close 형태로 생각해보면 풀이가 가능
// 먼저 여는 것에 대해서 +1을 적용하고, 닫히는 경우 -1을 적용
// 단, 매 번 열고 닫는 행위에 대해서는 가장 큰 값을 유지해야 동시에 진행되는 회의 수를 알 수 있음
// 1 -1 1 1 1 -1 -1 -1과 같은 경우 회의 시작 -> 회의 끝남 -> 회의 시작 -> 회의 시작 -> 회의 시작 -> 회의 끝남 -> 회의 끝남 -> 회의 끝남
// 즉, 처음에 제시된 시작과 끝은 하나의 묶음이 되고 이 때의 동시에 진행되는 회의 수는 1개가 됨
// 하지만 그 이후에 진행되는 연속된 회의 시작 3개는 각각 회의 끝남과 매칭되지 않고서 시작이 연달아 열렸으므로 3개의 회의가 동시에 진행됨을 알 수 있음
// 따라서 위의 경우에는 3개의 회의가 동시에 진행됨

type Meeting struct {
	Time int // 회의 시간
	Type int // 회의 시간의 시작 혹은 끝 구분 (1은 시작, -1은 끝)
}

type Data struct {
	R                *bufio.Reader
	W                *bufio.Writer
	Answer           int       // 정답
	NumberOfMeetings int       // 회의 개수
	Meetings         []Meeting // 회의 정보들
}

func inputAction() *Data {
	d := &Data{Meetings: []Meeting{}}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.NumberOfMeetings)
	for i := 0; i < d.NumberOfMeetings; i++ {
		var start, finish int
		fmt.Fscan(d.R, &start, &finish)
		d.Meetings = append(d.Meetings, Meeting{Time: start, Type: 1})
		d.Meetings = append(d.Meetings, Meeting{Time: finish, Type: -1})
	}
	return d
}

func maxInt(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func countMeetingRooms(d *Data) {
	currentProcess := 0
	for i := 0; i < len(d.Meetings); i++ {
		currentProcess += d.Meetings[i].Type
		d.Answer = maxInt(d.Answer, currentProcess)
	}
}

func Solution(d *Data) {
	sort.Slice(d.Meetings, func(i, j int) bool {
		if d.Meetings[i].Time < d.Meetings[j].Time {
			return true
		} else if d.Meetings[i].Time == d.Meetings[j].Time && d.Meetings[i].Type < d.Meetings[j].Type {
			return true
		}
		return false
	})
	countMeetingRooms(d)
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
