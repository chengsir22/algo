package leetcode

import (
	"fmt"
	"testing"
)

func Test_reverseString(t *testing.T) {
	src := []rune("你好abc啊哈哈")
	reverseRune(src)
	fmt.Printf("%v\n", string(src))
}
