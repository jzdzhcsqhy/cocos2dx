#include "HelloWorldScene.h"
#include "Tetris.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    
	//CCSprite* background = CCSprite::create("source\\scene\\CHANGANS.jpg");
	CCSprite* background = CCSprite::create("scene\\dt.jpg");
	// position the sprite on the center of the screen
	background->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	// add the sprite as a child to this layer
	this->addChild(background, 0);
	    
	CCSprite* tiger = CCSprite::create("0034-431506b-00000.png");
	tiger->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(tiger);

	CCScale9Sprite* btDown = CCScale9Sprite::create("CloseNormal.png");

	CCScale9Sprite* btUp = CCScale9Sprite::create("CloseSelected.png");
	CCLabelTTF* text = CCLabelTTF::create("Click","Show",30);
	CCControlButton* bt = CCControlButton::create(text, btDown);
	bt->setBackgroundSpriteForState(btDown,CCControlStateSelected);
	bt->setPosition(ccp(50,50));
	
	bt->addTargetWithActionForControlEvents(this,
											cccontrol_selector(HelloWorld::touchDown),
											CCControlEventTouchDown
											);
	
	this->addChild(bt);

	CCMoveTo* moveto = CCMoveTo::create(5.0f, ccp(50,50));	
//	tiger->runAction(moveto);

	CCJumpBy* jmpb = CCJumpBy::create(1.0f,ccp(0,0), 100, 1);

// 	CCRepeatForever* rpf = CCRepeatForever::create(jmpb);
// 
// 	tiger->runAction(rpf);

// 	ccBezierConfig bezier;
// 	bezier.controlPoint_1=ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
// 	bezier.controlPoint_2=ccp(350,150);
// 	bezier.endPosition=ccp(50,50);
// 
// 	CCBezierTo* bz = CCBezierTo::create(5.0f, bezier);
// 	tiger->runAction(bz);

	CCScaleTo* tobig = CCScaleTo::create(5.0f, 2.0f, 1.5f);
//	tiger->runAction(tobig);

 	CCBlink* blink = CCBlink::create(5.0f,3);
// 	tiger->runAction(blink);
//	CCAction* actionss = CCSpawn::create(moveto, jmpb, tobig, blink, NULL);
	CCAction* actionss = CCSequence::create(moveto, jmpb, tobig, blink, NULL);
	tiger->runAction(actionss);
	this->scheduleUpdate();
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
// #if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
// 	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
// #else
//     CCDirector::sharedDirector()->end();
// #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//     exit(0);
// #endif
// #endif

	CCScene* pScene = CMainFrame::scene();
	
	//CCDirector::sharedDirector()->replaceScene(pScene);
	CCDirector::sharedDirector()->replaceScene(
			CCTransitionSlideInT::create(0.5f,pScene)
		);
}

void HelloWorld::touchDown(CCObject* pSender, CCControlEvent event )
{
	
}