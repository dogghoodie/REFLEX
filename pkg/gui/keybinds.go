package gui

import (
	"github.com/jroimartin/gocui"
)

// PERF : INITIALIZE KEYBINDS
func InitializeKeybinds(g *gocui.Gui) error {
	// WARN : Leave CTRL+C bound to safely close Gui. Obv CTRL+C will close anyway.
	if err := g.SetKeybinding("", gocui.KeyCtrlC, gocui.ModNone, func(g *gocui.Gui, v *gocui.View) error {
		return gocui.ErrQuit
	}); err != nil {
		return err
	}

	if err := g.SetKeybinding("", gocui.KeyEsc, gocui.ModNone, func(g *gocui.Gui, v *gocui.View) error {
		return gocui.ErrQuit
	}); err != nil {
		return err
	}

	return nil
}
