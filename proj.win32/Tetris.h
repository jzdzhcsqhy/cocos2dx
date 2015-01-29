#ifndef __TETRIS_H__
#define	__TETRIS_H__

#include "cocos2d.h"

using namespace cocos2d;

class CMainFrame : public cocos2d::CCLayer
{
public:
	virtual bool init();

	static CCScene* scene();

	CREATE_FUNC(CMainFrame);
};
#endif