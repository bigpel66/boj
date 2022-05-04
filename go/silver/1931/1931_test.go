package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var d = &Data{}

func TestInput(t *testing.T) {
	assert := assert.New(t)
	d.NumberOfMeeting = 11
	d.Meetings = []MeetingSchedule{
		{StartTime: 1, FinishTime: 4},
		{StartTime: 3, FinishTime: 5},
		{StartTime: 0, FinishTime: 6},
		{StartTime: 5, FinishTime: 7},
		{StartTime: 3, FinishTime: 8},
		{StartTime: 5, FinishTime: 9},
		{StartTime: 6, FinishTime: 10},
		{StartTime: 8, FinishTime: 11},
		{StartTime: 8, FinishTime: 12},
		{StartTime: 2, FinishTime: 13},
		{StartTime: 12, FinishTime: 14},
	}
	Solution(d)
	assert.Equal(4, d.Answer)
}
