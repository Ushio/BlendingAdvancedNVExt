#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;

	settings.width = 1280;
	settings.height = 720;
	settings.windowMode = OF_WINDOW;
	settings.multiMonitorFullScreen = true;
	//settings.glVersionMajor = 4;
	//settings.glVersionMinor = 5;
	ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
