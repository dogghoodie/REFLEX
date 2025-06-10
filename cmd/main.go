package main

import (
	"REFLEX/pkg/gui"
	"fmt"
	"os"
	"strconv"
)

// TODO : Pass the time to reflex
func main() {
	// NOTE : os.Args[1] is the first argument after the program name
	if len(os.Args) < 2 {
		fmt.Println("Usage: reflex <float64>")
		return
	}
	arg := os.Args[1]

	// CONVERT ARG STIRNG TO FLOAT64
	timeValue, err := strconv.ParseFloat(arg, 64)
	if err != nil {
		fmt.Println("Invalid time value:", err)
		return
	}

	// START GUI
	gui.Start()

	// TESTING
	// NOTE : setPrecision(2)
	// fmt.Sprintf("%.2f", f)
	fmt.Printf("Finished.%f", timeValue)
}
