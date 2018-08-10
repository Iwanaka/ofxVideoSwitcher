#pragma once

#include "ofxVideoSwitcher.h"
#define STR(var) #var

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		void keyReleased(int key);

		ofxImGui::Gui gui;

		ofxVideoSwitcher sVid;

		bool bMirror = false;
		bool bGui = true;
};
