#include "ofApp.h"

#define BLEND_ADVANCED_COHERENT_KHR                     0x9285

#define MULTIPLY_KHR                                    0x9294
#define SCREEN_KHR                                      0x9295
#define OVERLAY_KHR                                     0x9296
#define DARKEN_KHR                                      0x9297
#define LIGHTEN_KHR                                     0x9298
#define COLORDODGE_KHR                                  0x9299
#define COLORBURN_KHR                                   0x929A
#define HARDLIGHT_KHR                                   0x929B
#define SOFTLIGHT_KHR                                   0x929C
#define DIFFERENCE_KHR                                  0x929E
#define EXCLUSION_KHR                                   0x92A0

#define HSL_HUE_KHR                                     0x92AD
#define HSL_SATURATION_KHR                              0x92AE
#define HSL_COLOR_KHR                                   0x92AF
#define HSL_LUMINOSITY_KHR                              0x92B0

//--------------------------------------------------------------
void ofApp::setup() {
	ofstream ofs(ofToDataPath("ext.txt"));

	GLint n, i;
	glGetIntegerv(GL_NUM_EXTENSIONS, &n);
	for (i = 0; i < n; i++) {
		const GLubyte *e = glGetStringi(GL_EXTENSIONS, i);
		printf("%s\n", e);

		if (strcmp((const char *)e, "GL_KHR_blend_equation_advanced") == 0) {
			_GL_KHR_blend_equation_advanced = true;
		}
		if (strcmp((const char *)e, "GL_KHR_blend_equation_advanced_coherent") == 0) {
			_GL_KHR_blend_equation_advanced_coherent = true;
		}

		ofs << e << std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (_blendmode) {
	case 0: ofEnableAlphaBlending(); break;
	case MULTIPLY_KHR: glBlendEquation(MULTIPLY_KHR); break;
	case SCREEN_KHR: glBlendEquation(SCREEN_KHR); break;
	case OVERLAY_KHR: glBlendEquation(OVERLAY_KHR); break;
	case DARKEN_KHR: glBlendEquation(DARKEN_KHR); break;
	case LIGHTEN_KHR: glBlendEquation(LIGHTEN_KHR); break;
	case COLORDODGE_KHR: glBlendEquation(COLORDODGE_KHR); break;
	case COLORBURN_KHR: glBlendEquation(COLORBURN_KHR); break;
	case HARDLIGHT_KHR: glBlendEquation(HARDLIGHT_KHR); break;
	case SOFTLIGHT_KHR: glBlendEquation(SOFTLIGHT_KHR); break;
	case DIFFERENCE_KHR: glBlendEquation(DIFFERENCE_KHR); break;
	case EXCLUSION_KHR: glBlendEquation(EXCLUSION_KHR); break;
	case HSL_HUE_KHR: glBlendEquation(HSL_HUE_KHR); break;
	case HSL_SATURATION_KHR: glBlendEquation(HSL_SATURATION_KHR); break;
	case HSL_COLOR_KHR: glBlendEquation(HSL_COLOR_KHR); break;
	case HSL_LUMINOSITY_KHR: glBlendEquation(HSL_LUMINOSITY_KHR); break;
	}

	if (_blendmode != 0 && _GL_KHR_blend_equation_advanced_coherent) {
		glEnable(BLEND_ADVANCED_COHERENT_KHR);
	}

	srand(5);
	
	for (int i = 0; i < 10; ++i) {
		ofSetColor(ofRandom(0, 230), ofRandom(0, 230), ofRandom(0, 230));

		float x = ofRandom(0, ofGetWidth()) + ofRandom(0, ofGetWidth());
		float y = ofRandom(0, ofGetHeight()) + ofRandom(0, ofGetWidth());
		x *= 0.5;
		y *= 0.5;
		ofDrawCircle(x, y, 200);
	}

	ofEnableAlphaBlending();

	_imgui.begin();
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ofVec4f(0.0f, 0.2f, 0.2f, 1.0f));
	ImGui::SetNextWindowPos(ofVec2f(10, 30), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ofVec2f(500, ofGetHeight() * 0.8), ImGuiSetCond_Once);

	ImGui::Begin("Config Panel");
	ImGui::Text("GL_KHR_blend_equation_advanced : %s", _GL_KHR_blend_equation_advanced ? "Supported" : "No");
	ImGui::Text("GL_KHR_blend_equation_advanced_coherent : %s", _GL_KHR_blend_equation_advanced_coherent ? "Supported" : "No");

	ImGui::RadioButton("normal", &_blendmode, 0);
	ImGui::RadioButton("MULTIPLY_KHR", &_blendmode, MULTIPLY_KHR);
	ImGui::RadioButton("SCREEN_KHR", &_blendmode, SCREEN_KHR);
	ImGui::RadioButton("OVERLAY_KHR", &_blendmode, OVERLAY_KHR);
	ImGui::RadioButton("DARKEN_KHR", &_blendmode, DARKEN_KHR);
	ImGui::RadioButton("LIGHTEN_KHR", &_blendmode, LIGHTEN_KHR);
	ImGui::RadioButton("COLORDODGE_KHR", &_blendmode, COLORDODGE_KHR);
	ImGui::RadioButton("COLORBURN_KHR", &_blendmode, COLORBURN_KHR);
	ImGui::RadioButton("HARDLIGHT_KHR", &_blendmode, HARDLIGHT_KHR);
	ImGui::RadioButton("SOFTLIGHT_KHR", &_blendmode, SOFTLIGHT_KHR);
	ImGui::RadioButton("DIFFERENCE_KHR", &_blendmode, DIFFERENCE_KHR);
	ImGui::RadioButton("EXCLUSION_KHR", &_blendmode, EXCLUSION_KHR);

	ImGui::RadioButton("HSL_HUE_KHR", &_blendmode, HSL_HUE_KHR);
	ImGui::RadioButton("HSL_SATURATION_KHR", &_blendmode, HSL_SATURATION_KHR);
	ImGui::RadioButton("HSL_COLOR_KHR", &_blendmode, HSL_COLOR_KHR);
	ImGui::RadioButton("HSL_LUMINOSITY_KHR", &_blendmode, HSL_LUMINOSITY_KHR);

	ImGui::End();
	ImGui::PopStyleColor();

	_imgui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
