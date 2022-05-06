package main

import (
	"bufio"
	"fmt"
	"os"
)

// 3개의 케이스를 생각할 수 있음
// 첫 째는 빈 구멍이 있어서 멀티탭에 기기를 꽂을 수 있는 경우
// 둘 째는 꽂으려는 기기가 이미 꽂혀 있는 경우
// 셋 째는 기존에 꽂혀 있는 기기를 뽑아야 하는 경우
// 1, 2번 케이스는 그냥 루프에서 무시하면 되는데, 3번은 각각 멀티탭에 꽂혀 있는 값들이 현재 서칭하고 있는 인덱스로부터 마지막에 위치한 인덱스가 어느 것이 더 나중에 나오는지에 따라 분기
// 멀티탭에 꽂혀 있는 값들 중 마지막에 위치한 인덱스가 더 높은 값을 대치

type Data struct {
	R             *bufio.Reader
	W             *bufio.Writer
	Answer        int          // 정답
	NumberOfHole  int          // 멀티탭 구멍 수
	NumberOfUsage int          // 전기 용품 사용 횟수
	CurrentStatus map[int]bool // 전기 용품 사용 현황
	Electronics   []int        // 전기 용품 ID
}

func inputAction() *Data {
	d := &Data{CurrentStatus: map[int]bool{}, Electronics: []int{}}
	d.R = bufio.NewReader(os.Stdin)
	d.W = bufio.NewWriter(os.Stdout)
	fmt.Fscan(d.R, &d.NumberOfHole, &d.NumberOfUsage)
	for i := 0; i < d.NumberOfUsage; i++ {
		var id int
		fmt.Fscan(d.R, &id)
		d.Electronics = append(d.Electronics, id)
	}
	return d
}

func ignorePlugOut(d *Data, e int) bool {
	if _, ok := d.CurrentStatus[e]; ok {
		return true
	} else if len(d.CurrentStatus) < d.NumberOfHole {
		d.CurrentStatus[e] = true
		return true
	}
	return false
}

func conductPlugOut(d *Data, i, e int) {
	deviceId, lastIndex := -1, -1
	for key, val := range d.CurrentStatus {
		if !val {
			continue
		}
		searchIndex := 0
		for j := i + 1; j < d.NumberOfUsage; j++ {
			if key == d.Electronics[j] {
				break
			}
			searchIndex++
		}
		if lastIndex < searchIndex {
			lastIndex = searchIndex
			deviceId = key
		}
	}
	d.Answer++
	delete(d.CurrentStatus, deviceId)
	d.CurrentStatus[e] = true
}

func Solution(d *Data) {
	for i, e := range d.Electronics {
		if ignorePlugOut(d, e) {
			continue
		}
		conductPlugOut(d, i, e)
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
