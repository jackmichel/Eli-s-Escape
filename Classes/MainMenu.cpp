#include "MainMenu.h"
#include "Constants.h"
#include "Game.h"
#include "Options.h"
#include "LevelSelect.h"
#include "About.h"
#include "Utils.h"

using namespace cocos2d;

CCScene* MainMenu::scene() {
	CCScene *sc = CCScene::create();
	MainMenu *m = MainMenu::create();
	sc->addChild(m, 0);
	return sc;
}

bool MainMenu::init() {
	if ( !CCLayer::init() ) {
		return false;
	}

	windowSize = CCDirector::sharedDirector()->getWinSize();

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* bg = CCSprite::create("Start_Screen.png");
    bg->setPosition(ccp(windowSize.width/2,windowSize.height/2));
    Utils::scaleSprite(bg);
    this->addChild(bg,-1);

    //Create Menu and Menu Buttons
    CCMenuItemImage *levelButton = CCMenuItemImage::create("button.png", "button.png", this, menu_selector(MainMenu::levelSelect));
    CCMenuItemImage *optionsButton = CCMenuItemImage::create("button.png", "button.png", this, menu_selector(MainMenu::options));
    CCMenuItemImage *aboutButton = CCMenuItemImage::create("button.png", "button.png", this, menu_selector(MainMenu::about));
    playButton->setPosition(-42,250);
    optionsButton->setPosition(-84,100);
    aboutButton->setPosition(-140,-50);
    CCMenu *menu = CCMenu::create(levelButton, optionsButton, aboutButton, NULL);

    menu->setPosition(ccp(windowSize.width - 200, windowSize.height/2 - windowSize.height/4.0f));
    this->addChild(menu,2);

    return true;
}

void MainMenu::levelSelect()
{
    CCDirector::sharedDirector()->replaceScene(LevelSelect::scene());
}

void MainMenu::options()
{
    CCDirector::sharedDirector()->replaceScene(Options::scene());
}

void MainMenu::about()
{
    CCDirector::sharedDirector()->replaceScene(About::scene());
}

void MainMenu::mainMenu() {
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
