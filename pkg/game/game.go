package game

import (
	"fmt"
	"math/rand"
	"time"

	"github.com/jroimartin/gocui"
)

type Stats struct {
	streak  int
	avgTime float64
	bestKey byte
}

// TODO : Build game logic and determine if need move to gui
func Start(g *gocui.Gui, v *gocui.View) error {
	// NOTE : GAME LOGIC >>
	// while loop
	// check input
	// if char == target : continue next char, streak++
	// if char != target : break
	// prompt continue y/n

	// NOTE : HARD MODE >>
	// reflex view moves to random position each char

	rand.Seed(time.Now().UnixNano())

	TARGETS := []byte("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:',.<>?/~`")
	index := rand.Intn(26)

	randomChar := TARGETS[index]
	fmt.Fprintf(v, "%c", randomChar)
	return nil
}
