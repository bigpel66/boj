package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		inputData(25)
		assertAnswer(t, 1)
	})

	t.Run("Case 2", func(t *testing.T) {
		inputData(26)
		assertAnswer(t, 2)
	})

	t.Run("Case 3", func(t *testing.T) {
		inputData(11339)
		assertAnswer(t, 3)
	})

	t.Run("Case 4", func(t *testing.T) {
		inputData(34567)
		assertAnswer(t, 4)
	})

}

func inputData(value int) {
	d.Value = value
	d.Memoi = make([]int, d.Value+1)
	d.Memoi[1] = 1
}

func assertAnswer(t *testing.T, expected int) {
	t.Helper()
	assert := assert.New(t)
	Solution(d)
	assert.Equal(expected, d.Answer)
}
