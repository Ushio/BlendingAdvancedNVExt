#pragma once

#include "ofMain.h"
#include "ofxImGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxImGui _imgui;
	int _blendmode = 0;

	bool _GL_KHR_blend_equation_advanced = false;
	bool _GL_KHR_blend_equation_advanced_coherent = false;
};
