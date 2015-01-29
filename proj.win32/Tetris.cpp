#include "Tetris.h"

bool CMainFrame::init()
{
	CCSprite* sprite = CCSprite::create("CloseNormal.png");
	sprite->setPosition(ccp(200,200) );
	this->addChild(sprite);

	return true;
}

CCScene* CMainFrame::scene()
{
	CCScene* scene = CCScene::create();

	CMainFrame* frame = CMainFrame::create();
	scene->addChild(frame);
	return scene;
}