#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	sVid.video.setup(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

	sVid.video.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	if(!bMirror) sVid.video.draw(0, 0);
	else sVid.video.draw(0, 0, -sVid.video.getWidth(), -sVid.video.getHeight());

	if (!bGui) return;
	gui.begin();
	{

		sVid.gui();

	}
	gui.end();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	if (key == ' ') bGui = !bGui;
	if (key == 's') ofSaveScreen(ofGetTimestampString() + ".png");
}
