#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;  // try to grab at this size.
    camHeight = 240;
    
    //First Vert then Frag
    shader.load("shaderVert.vert", "shaderFrag.frag");
    //image1.load("image1.png");
    //image2.load("image2.jpg");
    //image3.load("image3.jpg");
    fbo.allocate(camWidth, camHeight);
    //image1.resize(image1.getWidth()/2-50, image1.getHeight()/2-50);
    //image2.resize(image2.getWidth()/2-50, image2.getHeight()/2-50);
    //image3.resize(image3.getWidth()/2-50, image3.getHeight()/2-50);
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    ofSetVerticalSync(true);

}


//--------------------------------------------------------------
void ofApp::update(){
    camera.setPosition(vidGrabber.getWidth()/2, vidGrabber.getHeight()/2, 300);
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.begin();
    
    fbo.begin();
    
    //ofBackgroundGradient( ofColor(255), ofColor(255));
    
    
    //ofSetColor( 255, 255, 255 );
    vidGrabber.draw( 25, 25 );
    
    
    fbo.end();
    
    shader.begin();
    
    float time = ofGetElapsedTimef();
    shader.setUniform1f("time", time);
    shader.setUniformTexture( "texture1", vidGrabber.getTextureReference(), 1 );
    shader.setUniformTexture( "texture2", vidGrabber.getTextureReference(), 2 );

    
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);
    
    shader.end();
    
    camera.end();
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
