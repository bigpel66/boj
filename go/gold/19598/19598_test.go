package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var d = &Data{}

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		d.NumberOfMeetings = 3
		d.Answer = 0
		d.Meetings = []Meeting{
			{0, 1},
			{40, -1},
			{15, 1},
			{30, -1},
			{5, 1},
			{10, -1},
		}
		assertAnswer(t, 2)
	})
	t.Run("Case 2", func(t *testing.T) {
		d.NumberOfMeetings = 2
		d.Answer = 0
		d.Meetings = []Meeting{
			{10, 1},
			{20, -1},
			{5, 1},
			{10, -1},
		}
		assertAnswer(t, 1)
	})
}

func assertAnswer(t *testing.T, expected int) {
	t.Helper()
	assert := assert.New(t)
	Solution(d)
	assert.Equal(expected, d.Answer)
}
