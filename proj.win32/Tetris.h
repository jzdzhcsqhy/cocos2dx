#ifndef __TETRIS_H__
#endif	__TETRIS_H__

#include "cocos2d.h"

class CMainFrame : public cocos2d::CCLayer
{
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(CMainFrame);
};
#endif