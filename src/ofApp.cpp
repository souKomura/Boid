#include "ofApp.h"
#include "ofxTimeMeasurements.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(false);
    ofSetFrameRate(30);
    
    //initialize all birds
    int num = 3000;
    birds.resize(num);
    for(int i=0; i<birds.size(); i++){
        birds[i] = Bird();
    }
    
    //shape of bird
    Bird::shape.addVertex(ofPoint(0, Bird::r));
    Bird::shape.addVertex(ofPoint(0, -Bird::r));
    Bird::shape.addVertex(ofPoint(Bird::r*2.6, 0));
    Bird::shape.addVertex(ofPoint(0, Bird::r));
}

//--------------------------------------------------------------
void ofApp::update(){
    //TS_START("measurement1");
        //my code here
    for(int i=0; i<birds.size(); i++){
        birds[i].update(birds);
    }
    //TS_STOP("measurement1");
    for(int i=0; i<birds.size(); i++){
        birds[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(80, 80, 80), ofColor(10, 10, 10));
    
    for(int i=0; i<birds.size(); i++){
        birds[i].draw();
    }
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
    birds.push_back(Bird(ofGetMouseX(), ofGetMouseY()));
    cout << birds.size() << endl;
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
