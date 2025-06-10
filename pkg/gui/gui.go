package gui

import (
	"github.com/jroimartin/gocui"
)

// PERF : CONFIGURE GUI SETTINGS
func Configuration(g *gocui.Gui) {
	g.ASCII = false
	g.Highlight = true
	g.Cursor = true
	g.InputEsc = true
	g.Cursor = false
	g.Mouse = false
}

// PERF : START GUI
func Start() error {
	// CREATE NEW GOCUI INSTANCE
	g, err := gocui.NewGui(gocui.OutputNormal)
	if err != nil {
		return err
	}

	// CLOSE GUI AT END OF RUNTIME
	defer g.Close()

	// LINK VIEW MANAGER
	g.SetManagerFunc(ViewManager)

	// INITIALIZE CONFIGURATION
	// WARN : Must initialize after SetManagerFunc
	Configuration(g)

	// RETURN NON QUIT ERRORS
	if err := g.MainLoop(); err != nil && err != gocui.ErrQuit {
		return err
	}

	return nil
}
