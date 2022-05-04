package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var d = &Data{}

func TestInput(t *testing.T) {
	assert := assert.New(t)
	d.NumberOfLine = 4
	d.Lines = []Line{
		{1, 3},
		{2, 5},
		{3, 5},
		{6, 7},
	}
	Solution(d)
	assert.Equal(5, d.Answer)
}
