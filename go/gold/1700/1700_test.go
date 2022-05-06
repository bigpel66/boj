package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestInput(t *testing.T) {
	t.Run("Case 1", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 2
		d.NumberOfUsage = 7
		d.Electronics = []int{2, 3, 2, 3, 1, 2, 7}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(2, d.Answer)
	})
	t.Run("Case 2", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 2
		d.NumberOfUsage = 5
		d.Electronics = []int{5, 2, 2, 3, 5}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(1, d.Answer)
	})
	t.Run("Case 3", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 2
		d.NumberOfUsage = 4
		d.Electronics = []int{5, 3, 1, 5}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(1, d.Answer)
	})
	t.Run("Case 4", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 3
		d.NumberOfUsage = 6
		d.Electronics = []int{1, 1, 1, 1, 2, 3}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(0, d.Answer)
	})
	t.Run("Case 5", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 3
		d.NumberOfUsage = 8
		d.Electronics = []int{1, 2, 3, 4, 1, 1, 1, 2}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(1, d.Answer)
	})
	t.Run("Case 6", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 2
		d.NumberOfUsage = 15
		d.Electronics = []int{3, 2, 1, 2, 1, 2, 1, 2, 1, 3, 3, 3, 3, 3, 3}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(2, d.Answer)
	})
	t.Run("Case 7", func(t *testing.T) {
		var d = &Data{}
		assert := assert.New(t)
		d.NumberOfHole = 1
		d.NumberOfUsage = 3
		d.Electronics = []int{1, 2, 1}
		d.CurrentStatus = map[int]bool{}
		Solution(d)
		assert.Equal(2, d.Answer)
	})
}
