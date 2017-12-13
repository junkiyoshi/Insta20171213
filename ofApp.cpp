#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetColor(0);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateZ(ofGetFrameNum());

	int deg_span = 3;
	float radius = 0;
	float radius_default = 30;
	float radius_span = 5;
	int layer = 8;
	float x, y, z;

	for (int deg = 0; deg < 360; deg += deg_span) {
		radius = radius_default;
		for (int i = 0; i < layer; i++) {

			ofBeginShape();

			for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg += 1) {
				x = radius * cos(tmp_deg * DEG_TO_RAD);
				y = radius * sin(tmp_deg * DEG_TO_RAD);
				z = ofMap(ofNoise(i * 0.2, x * 0.005, y * 0.005, ofGetFrameNum() * 0.005), 0, 1, -100, 100);
				ofVertex(x, y, z);
			}

			for (int tmp_deg = deg + deg_span; tmp_deg >= deg; tmp_deg -= 1) {
				x = (radius + radius_span) * cos(tmp_deg * DEG_TO_RAD);
				y = (radius + radius_span) * sin(tmp_deg * DEG_TO_RAD);
				z = ofMap(ofNoise(i * 0.2, x * 0.005, y * 0.005, ofGetFrameNum() * 0.005), 0, 1, -100, 100);
				ofVertex(x, y, z);
			}

			ofEndShape(true);

			radius += radius_span;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}