#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
//    gallery.setPosition(0, 200).setSize(ofGetWindowWidth(), ofGetWindowHeight()*0.5);
//    gallery.setMode(HORIZONTAL_ALIGN);
#if defined (TARGET_OSX) //|| defined(TARGET_LINUX) // only working on Mac/Linux at the moment (but on Linux you need to run as sudo...)
	hardware.setup();				// libusb direct control of motor, LED and accelerometers
	hardware.setLedOption(LED_OFF); // turn off the led just for yacks (or for live installation/performances ;-)
#endif
	
	context.setup();
	depthGenerator.setup(&context);
	userGenerator.setup(&context);
	wave.setup(&context);
	wave.addGesture("mano");
}

//--------------------------------------------------------------
void testApp::update(){
//	gallery.update();
	userGenerator.update();
	ofSetWindowTitle( "fps: "+ ofToString(ofGetFrameRate(), 2) );
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackgroundGradient(ofColor::gray, ofColor::black);
	
//	gallery.draw();
    userGenerator.draw(640, 480);
    ofSetColor(255);
	ofDrawBitmapString("Drag image files into this window", 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	switch (key){
		case 'f':
			ofToggleFullscreen();
			break;
		case 't':
//			gallery.bDebug = !gallery.bDebug;
			break;
        case 'v':
//            gallery.setMode(VERTICAL_ALIGN);
            break;
        case 'h':
//            gallery.setMode(HORIZONTAL_ALIGN);
            break;
        case 'e':
//            gallery.setMode(FREE);
            break;
        case 'd':
//            gallery.del( gallery.getSelected() );
        case OF_KEY_LEFT:
//            gallery.moveBackward();
            break;
        case OF_KEY_RIGHT:
//            gallery.moveFoward();
            break;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
//    gallery.setSize(w, h*0.5);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){
//	if( info.files.size() > 0 ){
//		for(int k = 0; k < info.files.size(); k++){
//			gallery.loadPhoto(info.files[k]);
//		}
//	}
//    gallery.setMode(HORIZONTAL_ALIGN);
}
