#include "SimpleSoundScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

SimpleSound::~SimpleSound()
{
}

SimpleSound::SimpleSound() : bpm_(120), resolution_(8), marker_(0)
{
}

CCScene* SimpleSound::scene()
{
	CCScene * scene = NULL;
	do
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);
    
		// 'layer' is an autorelease object
		SimpleSound *layer = SimpleSound::create();
		CC_BREAK_IF(! layer);
    
		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);
  
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SimpleSound::init()
{
	bool bRet = false;
	do
	{
		//////////////////////////////////////////////////////////////////////////
		// super init first
		//////////////////////////////////////////////////////////////////////////
    
		CC_BREAK_IF(! CCLayerColor::initWithColor( ccc4(255,255,255,255) ) );
    
		//////////////////////////////////////////////////////////////////////////
		// add your codes below...
		//////////////////////////////////////////////////////////////////////////

    // setup the sound schedule
    int measure = kMinutesInMicroSeconds / bpm_ * kDefaultBeats;
    int interval_in_microsec = measure / resolution_;
    float interval = interval_in_microsec /
        static_cast<float>(kSecondsInMicroSeconds);
    this->schedule(schedule_selector(SimpleSound::playSound), interval);
    
    // setup effects volume
    float volume = 1.0f / kNumberOfInstruments;
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
    
    
		bRet = true;
	} while (0);
  
	return bRet;
}

void SimpleSound::playSound() {
  int value = rand() % 6;
  
  // play melody
  if (value == 0) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("melody_C4.wav");
  } else if (value == 1) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("melody_D4.wav");
  } else if (value == 2) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("melody_E4.wav");
  } else if (value == 3) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("melody_G4.wav");
  } else if (value == 4) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("melody_A4.wav");
  } else {
    // a rest
  }
  
  // play base
  if (marker_ % 2 == 0) {
    value = rand() % 5;
    if (value == 0) {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("base_C3.wav");
    } else if (value == 1) {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("base_D3.wav");
    } else if (value == 2) {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("base_E3.wav");
    } else if (value == 3) {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("base_G3.wav");
    } else if (value == 4) {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("base_A3.wav");
    }
  }
  
  // update marker
  marker_ = (marker_ + 1) % resolution_;
}
