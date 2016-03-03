#include "testApp.h"

testApp::testApp() :
    poorsignal("Poor Signal", 100, 100, 200, 20, 0, 0, 255),
    power("Poor Signal", 100, 150, 200, 20, 0, 0, 255),
    attention("Poor Signal", 100, 200, 200, 20, 0, 0, 100),
    meditation("Poor Signal", 100, 250, 200, 20, 0, 0, 100),
    blink("Blink", 100, 300, 200, 20, 0, 0, 255)
{
}

//--------------------------------------------------------------
void testApp::setup(){
    //setup brainwave headset
    tg.addEventListener(this);
    
    //load image and setup blur
    img.loadImage("image/img.jpg");
    blur.setup(img.getWidth(), img.getHeight(), 4, .2, 4);

    //setup up on screen info visibility (on/off)
    showInfo = false;
    
    poorsignal.draw();
    power.draw();
    attention.draw();
    meditation.draw();
    blink.draw();
}

//--------------------------------------------------------------
void testApp::update(){
    //update brainwave sensor data
    tg.update();
    
    //update blur amount
    blur.setScale(ofMap(meditation.value, 80, 0, 0, 8));
    blur.setRotation(ofMap(meditation.value, 80, 0, -PI, PI));
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofBackground(0);
    
    blur.begin();
    ofSetColor(255);
    img.draw(0, 0);
    blur.end();
    
    blur.draw();
    
    

    
    if(showInfo){
    
    if (tg.isReady)
        ofDrawBitmapString("headset connected", 10, 20);
    else
        ofDrawBitmapString("headset not connected", 10, 20);
 
        ofDrawBitmapString("meditation level = " + ofToString(meditation.value), 10, 34);
        ofDrawBitmapString("fps = "+ofToString((int) ofGetFrameRate()), 10, 48);
        
        ofDrawBitmapString("poor signal", 10, 115);
        poorsignal.draw();
        ofDrawBitmapString("power", 10, 162);
        power.draw();
        ofDrawBitmapString("attention", 10, 215);
        attention.draw();
        ofDrawBitmapString("meditation", 10, 265);
        meditation.draw();
        //blink.draw();

    }

    cout << "meditation level = " << meditation.value << endl;
    cout << "attention level = " << attention.value << endl;
    cout << "blink = " << blink.value << endl;

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'h' || key == 'H' || key == OF_KEY_TAB){
        showInfo = !showInfo;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::onThinkgearReady(ofxThinkgearEventArgs& args){
    cout << "onReady" << endl;
}

void testApp::onThinkgearError(ofMessage& err){
    cout << "onError " << err.message << endl;
}

void testApp::onThinkgearRaw(ofxThinkgearEventArgs& args){
}

void testApp::onThinkgearPower(ofxThinkgearEventArgs& args){
    power.value = args.power;
}

void testApp::onThinkgearPoorSignal(ofxThinkgearEventArgs& args){
    poorsignal.value = args.poorSignal;
}

void testApp::onThinkgearBlinkStrength(ofxThinkgearEventArgs& args){
    blink.value = args.blinkStrength;
}

void testApp::onThinkgearAttention(ofxThinkgearEventArgs& args){
    attention.value = args.attention;
}

void testApp::onThinkgearMeditation(ofxThinkgearEventArgs& args){
    meditation.value = args.meditation;
}

void testApp::onThinkgearEeg(ofxThinkgearEventArgs& args){
}

void testApp::onThinkgearConnecting(ofxThinkgearEventArgs& args){
}
