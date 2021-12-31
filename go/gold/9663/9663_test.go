package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	assert := assert.New(t)
	d.Size = 8
	d.Tile = make([]int, d.Size)
	Solution(d, 0)
	assert.Equal(92, d.Answer)
}
