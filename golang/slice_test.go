package golang_test

import (
	"fmt"
	"testing"
)

func TestArray(t *testing.T) {

	var a [3]int                                  // elements in the array are set to default value
	b := [3]int{1, 2}                             // [1 2 0]
	c := [...]int{1, 2, 3, 4, 5}                  // [1 2 3 4 5] len 5
	d := a                                        // copy assignment
	d[0] = 100                                    // does not affect array a
	e := [...]int{1: 101, 2: 102, 4: 104, 9: 109} // [0 101 102 0 104 0 0 0 0 109] len 9

	fmt.Printf("a=%v, b=%v, c=%v, d=%v, e=%v\n", a, b, c, d, e)
}

func TestSliceBase(t *testing.T) {

	a := make([]int, 0, 30)
	fmt.Printf("a=%v, len(a)=%v, cap(a)=%v\n", a, len(a), cap(a))
}
