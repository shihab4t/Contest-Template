package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() {

}

func main() {
	io := newBuffIO()
	defer io.Flush()

	// var t int
	// io.Read(&t)
	// for i := 1; i <= t; i++ {
	// 	solve()
	// 	// io.Write("Case #%d:\n", i)
	// }
}

type buffIO struct {
	r *bufio.Reader
	w *bufio.Writer
}

func newBuffIO() buffIO {
	return buffIO{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}

func (io *buffIO) Read(args ...interface{}) {
	_, _ = fmt.Fscan(io.r, args...)
}

func (io *buffIO) Write(format string, args ...interface{}) {
	_, _ = fmt.Fprintf(io.w, format, args...)
}

func (io *buffIO) Flush() {
	_ = io.w.Flush()
}
