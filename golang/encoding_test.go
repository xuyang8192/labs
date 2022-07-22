package golang_test

import (
	"fmt"
	"reflect"
	"testing"
)

func TestEncoding(t *testing.T) {
	fmt.Print("\nTest ASCII Characters\n")
	s := "Hello World!"
	for i := 0; i < len(s); i++ {
		b := s[i]
		fmt.Printf("b=%v, type=%v\n", b, reflect.TypeOf(b))
	}

	s = "哈哈哈"
	fmt.Print("\nTest Unicode Characters\n")
	fmt.Printf("content=%v, len=%v\n", s, len(s))
	for i := 0; i < len(s); i++ {
		b := s[i]
		fmt.Printf("b=%v, type=%v\n", b, reflect.TypeOf(b))
	}
}
