package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Solution은 핵심 로직을 담당
// 입력으로 받은 회의 목록들은 하루에 이뤄지는 것임
// 하루에 가장 많은 회의 수를 만들어내기 위해선 제한된 시간을 가장 타이트 하게 이용할수 있어야 함
// 그 말은 0시 ~ 4시까지의 상황에서 1 ~ 4를 차지하는 1개의 회의를 선택하는 것보다, 1 ~ 2와 2 ~ 2 그리고 2 ~ 4의 회의를 선택하는 것이 더 많은 회의 수를 가져다 줌
// 즉, 끝나는 시간이 작은 순서대로 경우의 수를 그리디하게 순서대로 가져가면 됨
// 위와 같은 케이스를 정리해보자면, 2가지 과정을 통해 정리됨
// 1. 회의의 끝나는 시간이 가장 낮은 순서대로 정렬
// 2. 회의의 끝나는 시간이 동일한 경우, 시작 시간이 더 빠른 것을 우선적으로 나타내도록 정렬
// 정렬된 값들에서 처음부터 회의의 수를 세는데, current의 끝 시간과 current + 1의 시작 시간의 비교를 통해 회의를 셈

type MeetingSchedule struct {
	StartTime  int
	FinishTime int
}

type Data struct {
	R               *bufio.Reader
	W               *bufio.Writer
	Answer          int
	NumberOfMeeting int
	Meetings        []MeetingSchedule
}

func inputAction() *Data {
	d := &Data{Meetings: []MeetingSchedule{}}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.NumberOfMeeting)
	for i := 0; i < d.NumberOfMeeting; i++ {
		schedule := MeetingSchedule{}
		fmt.Fscan(d.R, &schedule.StartTime, &schedule.FinishTime)
		d.Meetings = append(d.Meetings, schedule)
	}
	return d
}

func countMeetings(d *Data) {
	d.Answer++
	latestFinishTime := d.Meetings[0].FinishTime
	for i := 1; i < d.NumberOfMeeting; i++ {
		if latestFinishTime <= d.Meetings[i].StartTime {
			d.Answer++
			latestFinishTime = d.Meetings[i].FinishTime
		}
	}
}

func Solution(d *Data) {
	sort.Slice(d.Meetings, func(i, j int) bool {
		if d.Meetings[i].FinishTime < d.Meetings[j].FinishTime {
			return true
		} else if d.Meetings[i].FinishTime == d.Meetings[j].FinishTime && d.Meetings[i].StartTime < d.Meetings[j].StartTime {
			return true
		}
		return false
	})
	countMeetings(d)
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
