#pragma once

#include "ofMain.h"
#include "ofxImGui.h"

class ofxVideoSwitcher
{
public:

	ofxVideoSwitcher();
	~ofxVideoSwitcher();

	void setDeviceId(const int& id);
	void updateDeviceList();
	void apply();
	void gui();

	ofVideoGrabber video;

private:

#define STR(var) #var

	vector<ofVideoDevice> devices;

	std::string deviceName;
	int deviceID;
	int pixFormatId;

};

