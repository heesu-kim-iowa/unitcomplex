#include "ofApp.h"

/// Fnc for exp
complex<double> exp_complex(complex<double> v) {
	assert(v.real() == 0);
	double theta = v.imag();
	return complex<double>(cos(theta), sin(theta));	
}

complex<double> log_complex(complex<double> z) {
	double mag = sqrt(z.real()*z.real() + z.imag()*z.imag());
	assert(mag > 0);
	double theta = asin(z.imag());		
	return complex<double>(0, theta);
}

//--------------------------------------------------------------
void ofApp::setup(){
	t = 0;

	p0 = complex<double>(-0.5, -0.5);
	p1 = complex<double>(0.5, -0.5);
	p2 = complex<double>(0.5, 0.5);
	p3 = complex<double>(-0.5, 0.5);

	r1 = complex<double>(cos(PI/8), sin(PI/8));
	r2 = complex<double>(cos(PI/3), sin(PI/3));		// WHEN (theta_2 > PI), SOMEHING IS GOING WRONG SO THAT ROTATION TO r2 SHOWS WRONG RESULT. (AND IT ROTATES IN THE DIRECTION THAT HAS THE SMALLEST CHAGNE OF DEGREE)
	t1 = complex<double>(2, 1);
	t2 = complex<double>(-1.5, -1);

	s = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

	s = ofGetMouseX();
	s /= ofGetWidth();

	t = (1 - s)*t1 + s * t2;
	inv_r1 = complex<double>(r1.real(), -r1.imag());
	v = log_complex(inv_r1*r2);		
	r = r1*exp_complex(s*v);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);

	// translation must be eariler than scale
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);	// translate
	ofScale(100, -100);		// scale

	ofSetColor(255, 200, 50);	// yellow
	
	ofBeginShape();
	ofVertex(p0.real(), p0.imag());
	ofVertex(p1.real(), p1.imag());
	ofVertex(p2.real(), p2.imag());
	ofVertex(p3.real(), p3.imag());
	ofEndShape();

	// p0, p1, p2, p3 --(r1, t1)--> p0_, p1_, p2_, p3_
	complex<double> p0_ = r1 * p0 + t1;
	complex<double> p1_ = r1 * p1 + t1;
	complex<double> p2_ = r1 * p2 + t1;
	complex<double> p3_ = r1 * p3 + t1;
	ofSetColor(255, 0, 0);		// red
	ofBeginShape();
	ofVertex(p0_.real(), p0_.imag());
	ofVertex(p1_.real(), p1_.imag());
	ofVertex(p2_.real(), p2_.imag());
	ofVertex(p3_.real(), p3_.imag());
	ofEndShape();

	// p0, p1, p2, p3 --(r2, t2)--> p0__, p1__, p2__, p3__
	complex<double> p0__ = r2 * p0 + t2;
	complex<double> p1__ = r2 * p1 + t2;
	complex<double> p2__ = r2 * p2 + t2;
	complex<double> p3__ = r2 * p3 + t2;
	ofSetColor(0, 0, 255);	// blue
	ofBeginShape();
	ofVertex(p0__.real(), p0__.imag());
	ofVertex(p1__.real(), p1__.imag());
	ofVertex(p2__.real(), p2__.imag());
	ofVertex(p3__.real(), p3__.imag());
	ofEndShape();

	// p0, p1, p2, p3 --(r, t)--> p0s, p1s, p2s, p3s
	complex<double> p0s = r * p0 + t;
	complex<double> p1s = r * p1 + t;
	complex<double> p2s = r * p2 + t;
	complex<double> p3s = r * p3 + t;
	ofSetColor(0, 255, 0);	// green
	ofBeginShape();
	ofVertex(p0s.real(), p0s.imag());
	ofVertex(p1s.real(), p1s.imag());
	ofVertex(p2s.real(), p2s.imag());
	ofVertex(p3s.real(), p3s.imag());
	ofEndShape();
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
