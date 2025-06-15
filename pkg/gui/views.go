package gui

import (
	// "REFLEX/pkg/game"
	"log"

	"github.com/jroimartin/gocui"
)

// TODO : Update reflex view color upon keypress

// MAIN GAME VIEW
func InitializeReflexView(g *gocui.Gui) error {
	// TODO : Make global
	maxX, maxY := g.Size()
	width := 12
	height := 4
	x0 := (maxX - width) / 2
	y0 := (maxY - height) / 2
	x1 := x0 + width
	y1 := y0 + height

	// CONSTRUCT REFLEX VIEW
	if reflex, err := g.SetView("reflex", x0, y0, x1, y1); err != nil {
		if err != gocui.ErrUnknownView {
			return err
		}
		reflex.Title = ">>TARGET"
		reflex.Write([]byte("  .X"))
		reflex.Autoscroll = true
		reflex.Wrap = true
	}

	return nil
}

// TIME BAR 0-N SECONDS
func InitializeTimeView(g *gocui.Gui) error {
	// TODO : Make global
	maxX, maxY := g.Size()
	width := 12
	height := 2
	x0 := (maxX - width) / 2
	y0 := (maxY - height) / 2
	x1 := x0 + width
	y1 := y0 + height

	// Construct time view
	if time, err := g.SetView("time", x0, y0+4, x1, y1+4); err != nil {
		if err != gocui.ErrUnknownView {
			return err
		}
		time.Title = ""
	}

	// NOTE : Maybe print time bar with ansi escape codes
	return nil
}

// PERF: SET CURRENT VIEW AND APPLY SETTINGS
func SetMainView(g *gocui.Gui) error {
	// SET REFLEX TO CURRENT VIEW
	g.Update(func(gui *gocui.Gui) error {
		if _, err := g.SetCurrentView("reflex"); err != nil {
			log.Panicln("Error setting current view: ", err)
		}
		g.FgColor = gocui.ColorDefault
		g.SelFgColor = gocui.ColorGreen

		return nil
	})

	return nil
}

// CONTROL ALL VIEWS
func ViewManager(g *gocui.Gui) error {
	InitializeReflexView(g)
	InitializeTimeView(g)
	InitializeKeybinds(g)
	SetMainView(g)

	/*
		if reflexView, err := g.View("reflex"); err == nil {
			game.Start(g, reflexView)
		} else {
			log.Panicln("Error getting reflex view: ", err)
		}
	*/

	return nil
}
