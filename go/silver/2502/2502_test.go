package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		inputData(6, 41)
		assertAnswer(t, 2, 7)
	})

	t.Run("Case 2", func(t *testing.T) {
		inputData(7, 218)
		assertAnswer(t, 2, 26)
	})

	t.Run("Case 3", func(t *testing.T) {
		inputData(3, 10)
		assertAnswer(t, 1, 9)
	})
}

func inputData(day, number int) {
	d.Day = day
	d.Number = number
	d.CoefA = make([]int, d.Day+1)
	d.CoefB = make([]int, d.Day+1)
	d.CoefA[1] = 1
	d.CoefB[2] = 1
}

func assertAnswer(t *testing.T, expected1, expected2 int) {
	t.Helper()
	assert := assert.New(t)
	Solution(d)
	assert.Equal(expected1, d.Answer1)
	assert.Equal(expected2, d.Answer2)
}
