#include "ofxVideoSwitcher.h"

//--------------------------------------------------------------
ofxVideoSwitcher::ofxVideoSwitcher():
	deviceID(0),
	deviceName(""),
	pixFormatId(9)
{
	updateDeviceList();
	resolution[0] = 640;
	resolution[1] = 480;
}

//--------------------------------------------------------------
ofxVideoSwitcher::~ofxVideoSwitcher()
{}

//--------------------------------------------------------------
void ofxVideoSwitcher::gui() {

	ImGui::Begin("ofxVideoSwitcher");
	{

		ImGui::PushID("ofxVideoSwitcher");
		{
			ImGui::BulletText("current device name : %s", deviceName.c_str());
			ImGui::BulletText("current device id   : %i", deviceID);

			if (ImGui::Button("update device list")) updateDeviceList();

			for (int i = 0; i < devices.size(); i++) {

				if (ImGui::RadioButton(devices[i].deviceName.c_str(), &deviceID, i)) deviceName = devices[i].deviceName;

			}


			for each (ofVideoDevice device in devices)
			{
				if (ImGui::CollapsingHeader(device.deviceName.c_str())) {

					ImGui::BulletText("device id        : %i", device.id);
					ImGui::BulletText("device serial id : %s", device.serialID.c_str());
					ImGui::BulletText("device avariable : %i", device.bAvailable);
					ImGui::BulletText("device name      : %s", device.deviceName.c_str());
					ImGui::BulletText("hardware name    : %s", device.hardwareName.c_str());

					for each (ofVideoFormat f in device.formats)
					{

						ImGui::BulletText("format framerates : %f", f.framerates);
						ImGui::BulletText("format height     : %f", f.height);
						ImGui::BulletText("format width      : %f", f.width);
						ImGui::BulletText("pixel format      : %s", STR(f.pixelFormat));

					}
				}
			}

			if (ImGui::CollapsingHeader("option")) {


				static int p = 0;
				if (ImGui::RadioButton(STR(OF_PIXELS_GRAY), &p, 0)) pixFormatId = OF_PIXELS_GRAY;
				if (ImGui::RadioButton(STR(OF_PIXELS_GRAY_ALPHA), &p, 1)) pixFormatId = OF_PIXELS_GRAY_ALPHA;
				if (ImGui::RadioButton(STR(OF_PIXELS_BGR), &p, 2)) pixFormatId = OF_PIXELS_BGR;
				if (ImGui::RadioButton(STR(OF_PIXELS_BGRA), &p, 3)) pixFormatId = OF_PIXELS_BGRA;
				if (ImGui::RadioButton(STR(OF_PIXELS_I420), &p, 4)) pixFormatId = OF_PIXELS_I420;
				if (ImGui::RadioButton(STR(OF_PIXELS_NATIVE), &p, 5)) pixFormatId = OF_PIXELS_NATIVE;
				if (ImGui::RadioButton(STR(OF_PIXELS_NUM_FORMATS), &p, 6)) pixFormatId = OF_PIXELS_NUM_FORMATS;
				if (ImGui::RadioButton(STR(OF_PIXELS_NV12), &p, 7)) pixFormatId = OF_PIXELS_NV12;
				if (ImGui::RadioButton(STR(OF_PIXELS_NV21), &p, 8)) pixFormatId = OF_PIXELS_NV21;
				if (ImGui::RadioButton(STR(OF_PIXELS_RGB), &p, 9)) pixFormatId = OF_PIXELS_RGB;
				if (ImGui::RadioButton(STR(OF_PIXELS_RGB565), &p, 10)) pixFormatId = OF_PIXELS_RGB565;
				if (ImGui::RadioButton(STR(OF_PIXELS_RGBA), &p, 11)) pixFormatId = OF_PIXELS_RGBA;
				if (ImGui::RadioButton(STR(OF_PIXELS_U), &p, 12)) pixFormatId = OF_PIXELS_U;
				if (ImGui::RadioButton(STR(OF_PIXELS_UNKNOWN), &p, 13)) pixFormatId = OF_PIXELS_UNKNOWN;
				if (ImGui::RadioButton(STR(OF_PIXELS_UV), &p, 14)) pixFormatId = OF_PIXELS_UV;
				if (ImGui::RadioButton(STR(OF_PIXELS_UYVY), &p, 15)) pixFormatId = OF_PIXELS_UYVY;
				if (ImGui::RadioButton(STR(OF_PIXELS_V), &p, 16)) pixFormatId = OF_PIXELS_V;
				if (ImGui::RadioButton(STR(OF_PIXELS_VU), &p, 17)) pixFormatId = OF_PIXELS_VU;
				if (ImGui::RadioButton(STR(OF_PIXELS_Y), &p, 18)) pixFormatId = OF_PIXELS_Y;
				if (ImGui::RadioButton(STR(OF_PIXELS_YUY2), &p, 19)) pixFormatId = OF_PIXELS_YUY2;
				if (ImGui::RadioButton(STR(OF_PIXELS_YV12), &p, 20)) pixFormatId = OF_PIXELS_YV12;


			}


			ImGui::InputInt2("resolution", resolution, 0);
			

			if (ImGui::Button("apply use camera device")) {
				
				apply();
			
			}
			
		}
		ImGui::PopID();

	}
	ImGui::End();

}

//--------------------------------------------------------------
void ofxVideoSwitcher::setDeviceId(const int& id) { 

	deviceID = id; 

}

//--------------------------------------------------------------
void ofxVideoSwitcher::apply() {

	int w = resolution[0];
	int h = resolution[1];

	video.close();
	video.setDeviceID(deviceID);
	video.setPixelFormat(ofPixelFormat(pixFormatId));
	video.setup(resolution[0], h);


}

void ofxVideoSwitcher::updateDeviceList() {

	devices = video.listDevices();

}