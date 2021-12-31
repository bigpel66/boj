package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var d = &Data{}

func TestInput(t *testing.T) {
	assert := assert.New(t)
	d.X = 3
	d.Y = 5
	d.Tile = make([]string, d.X)
	d.Tile[0] = "42101"
	d.Tile[1] = "22100"
	d.Tile[2] = "22101"
	Solution(d)
	assert.Equal(9, d.Answer)
}
