package golang_test

import (
	"fmt"
	"reflect"
	"testing"
	"unsafe"
)

func TestBasicType(t *testing.T) {
	/* variables are all set to default value 0 */

	var sn int  // size at least 32 bits, holding 64 bits on a 64-bit system
	var un uint // size at least 32 bits, holding 64 bits on a 64-bit system
	fmt.Printf("sn=%v, type=%v, size=%v\n", sn, reflect.TypeOf(sn), unsafe.Sizeof(sn))
	fmt.Printf("un=%v, type=%v, size=%v\n", un, reflect.TypeOf(un), unsafe.Sizeof(un))
	fmt.Println()

	var n8 int8
	var n16 int16
	var n32 int32
	var n64 int64
	fmt.Printf("n8=%v, type=%v\n", n8, reflect.TypeOf(n8))
	fmt.Printf("n16=%v, type=%v\n", n16, reflect.TypeOf(n16))
	fmt.Printf("n32=%v, type=%v\n", n32, reflect.TypeOf(n32))
	fmt.Printf("n64=%v, type=%v\n", n64, reflect.TypeOf(n64))
	fmt.Println()

	var u8 uint8
	var u16 uint16
	var u32 uint32
	var u64 uint64
	fmt.Printf("u8=%v, type=%v\n", u8, reflect.TypeOf(u8))
	fmt.Printf("u16=%v, type=%v\n", u16, reflect.TypeOf(u16))
	fmt.Printf("u32=%v, type=%v\n", u32, reflect.TypeOf(u32))
	fmt.Printf("u64=%v, type=%v\n", u64, reflect.TypeOf(u64))
	fmt.Println()

	var f32 float32
	var f64 float64
	// no such type as double
	fmt.Printf("f32=%v, type=%v\n", f32, reflect.TypeOf(f32))
	fmt.Printf("f64=%v, type=%v\n", f64, reflect.TypeOf(f64))
	fmt.Println()

	var bl bool
	var rn rune // rune is an alias for int32 and is equivalent to int32 in all ways
	var bt byte // byte is an alias for uint8 and is equivalent to uint8 in all ways
	fmt.Printf("bl=%v, type=%v, size=%v\n", bl, reflect.TypeOf(bl), unsafe.Sizeof(bl))
	fmt.Printf("rn=%v, type=%v, size=%v\n", rn, reflect.TypeOf(rn), unsafe.Sizeof(rn))
	fmt.Printf("bt=%v, type=%v, size=%v\n", bt, reflect.TypeOf(bt), unsafe.Sizeof(bt))
	fmt.Println()

	// string is the set of all strings of 8-bit bytes, conventionally but not necessarily representing UTF-8-encoded text
	var s string
	// unsafe.Sizeof shows total sizes of its inner struct members
	fmt.Printf("s=\"%v\", type=%v, size=%v\n", s, reflect.TypeOf(s), unsafe.Sizeof(s))
	fmt.Println()
}

func TestLiteralType(t *testing.T) {
	t1 := 'r'
	fmt.Printf("t1=%v, type=%v\n", t1, reflect.TypeOf(t1))
	fmt.Println()
	// t2 := 'rr' // invalid

	t2 := "s"
	fmt.Printf("t2=%v, type=%v\n", t2, reflect.TypeOf(t2))
	fmt.Println()

	t3 := 100
	fmt.Printf("t3=%v, type=%v\n", t3, reflect.TypeOf(t3))
	fmt.Println()

	t4 := 2500000000 // 25亿
	fmt.Printf("2500000000 literal type=%v\n", reflect.TypeOf(2500000000))
	fmt.Printf("t4=%v, type=%v\n", t4, reflect.TypeOf(t4))
	fmt.Println()

	t5 := 5000000000 // 50亿
	fmt.Printf("5000000000 literal type=%v\n", reflect.TypeOf(5000000000))
	fmt.Printf("t5=%v, type=%v\n", t5, reflect.TypeOf(t5))
	fmt.Println()

	// t6 := int32(3500000000) // not valid
	// t6 := uint32(3500000000) // valid

	t7 := int64(5000000000)
	fmt.Printf("int64(5000000000) literal type=%v\n", reflect.TypeOf(int64(5000000000)))
	fmt.Printf("t7=%v, type=%v\n", t7, reflect.TypeOf(t7))
	fmt.Println()
}
