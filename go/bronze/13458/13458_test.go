package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		inputData(1, 1, 1)
		fillSlice(1)
		assertAnswer(t, 1)
	})

	t.Run("Case 2", func(t *testing.T) {
		inputData(3, 2, 2)
		fillSlice(3, 4, 5)
		assertAnswer(t, 7)
	})

	t.Run("Case 3", func(t *testing.T) {
		inputData(5, 5, 7)
		fillSlice(1000000, 1000000, 1000000, 1000000, 1000000)
		assertAnswer(t, 714290)
	})

	t.Run("Case 4", func(t *testing.T) {
		inputData(5, 7, 20)
		fillSlice(10, 9, 10, 9, 10)
		assertAnswer(t, 10)
	})

	t.Run("Case 5", func(t *testing.T) {
		inputData(5, 7, 2)
		fillSlice(10, 9, 10, 9, 10)
		assertAnswer(t, 13)
	})
}

func inputData(Place, Main, Sub int32) {
	d.Place = Place
	d.Main = Main
	d.Sub = Sub
	d.Answer = int(d.Place)
}

func fillSlice(People ...int32) {
	d.People = make([]int32, 0)
	d.People = append(d.People, People...)
}

func assertAnswer(t *testing.T, expected int) {
	t.Helper()
	assert := assert.New(t)
	Solution(d)
	assert.Equal(expected, d.Answer)
}
