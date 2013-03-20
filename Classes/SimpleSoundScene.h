#pragma once

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class SimpleSound : public cocos2d::CCLayerColor
{
public:
  SimpleSound();
  ~SimpleSound();

  // Here's a difference. Method 'init' in cocos2d-x returns bool,
  // instead of returning 'id' in cocos2d-iphone
  virtual bool init();
  
  // there's no 'id' in cpp, so we recommand to return the exactly class pointer
  static cocos2d::CCScene* scene();
  
  // implement the "static node()" method manually
  CREATE_FUNC(SimpleSound);
  
  void playSound();
  
protected:
  
  static const u_int32_t kMinutesInMicroSeconds = 60000000;
  static const u_int32_t kSecondsInMicroSeconds =  1000000;
  static const int kDefaultBeats                =        4;
  static const int kNumberOfInstruments         =        2;  // melody and base
  
  int bpm_;
  int resolution_;
  int marker_;
  
};
