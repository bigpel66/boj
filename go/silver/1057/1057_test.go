package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		inputData(16, 1, 2)
		assertAnswer(t, 1)
	})

	t.Run("Case 2", func(t *testing.T) {
		inputData(16, 8, 9)
		assertAnswer(t, 4)
	})

	t.Run("Case 3", func(t *testing.T) {
		inputData(1000, 20, 31)
		assertAnswer(t, 4)
	})

	t.Run("Case 5", func(t *testing.T) {
		inputData(65536, 1000, 35000)
		assertAnswer(t, 16)
	})

	t.Run("Case 6", func(t *testing.T) {
		inputData(60000, 101, 891)
		assertAnswer(t, 10)
	})
}

func inputData(Participants, Kim, Lim int) {
	d.Participants = Participants
	d.Kim = Kim
	d.Lim = Lim
}

func assertAnswer(t *testing.T, expected int) {
	t.Helper()
	assert := assert.New(t)
	Solution(d)
	assert.Equal(expected, d.Answer)
}
