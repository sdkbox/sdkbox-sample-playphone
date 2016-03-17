
#include "HelloWorldScene.h"

USING_NS_CC;
using namespace sdkbox;

#define kLevelLeaderBoardId "1434"
#define kSoldierAchievementId "3622"
#define fontsize 52

class MyLeaderboardListener : public sdkbox::LeaderboardListener
{
public:
    virtual void onComplete(std::string leaderboard)
    {
        CCLOG("MyLeaderboardListener:onComplete: %s", leaderboard.data());
    }
    virtual void onFail()
    {
        CCLOG("MyLeaderboardListener:onFail");
    }
};

template <typename T> std::string tostr(const T& t) {
    std::ostringstream os; os << t; return os.str();
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    IAP::setDebug(true);
    IAP::setListener(this);
    IAP::init();

    sdkbox::PluginAchievement::init();
    sdkbox::PluginLeaderboard::init();
    sdkbox::PluginLeaderboard::setListener(new MyLeaderboardListener);

    Size size = Director::getInstance()->getWinSize();

    _coinCount = 0;
    _txtCoin = Label::createWithSystemFont("0", "sans", 24);
    _txtCoin->setPosition(Vec2(size.width / 2, 60));
    addChild(_txtCoin);

    CCMenuItemFont::setFontSize(fontsize);

    _iapMenu = CCMenu::create();
    _iapMenu->setPosition(size.width/2, size.height-200);
    addChild(_iapMenu);

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("load products", "sans", fontsize), CC_CALLBACK_1(HelloWorld::onRequestIAP, this)));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("restore purchase", "sans", fontsize), CC_CALLBACK_1(HelloWorld::onRestoreIAP, this)));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("update leaderboard random [1,100]", "sans", fontsize), [](Ref*){
        int score = rand_0_1() * 100 + 1;
        PluginLeaderboard::submitScore(kLevelLeaderBoardId, score);
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("get leaderboard", "sans", fontsize), [](Ref*){
        PluginLeaderboard::getLeaderboard(kLevelLeaderBoardId);
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("achievement test", "sans", fontsize), [](Ref*){
        PluginAchievement::unlock(kSoldierAchievementId);
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

// callbacks

void HelloWorld::onShowAds(cocos2d::Ref *sender)
{
    CCLOG("Show Ads");
}

void HelloWorld::onRequestIAP(cocos2d::Ref* sender)
{
    IAP::refresh();
}

void HelloWorld::onRestoreIAP(cocos2d::Ref* sender)
{
    IAP::restore();
}

void HelloWorld::onIAP(cocos2d::Ref *sender)
{
    auto btn = static_cast<Node*>(sender);
    Product* p = (Product*)btn->getUserData();

    CCLOG("Start IAP %s", p->name.c_str());
    IAP::purchase(p->name);
}

void HelloWorld::onInitialized(bool ok)
{
    CCLOG("%s : %d", __func__, ok);
}

void HelloWorld::onSuccess(const Product &p)
{
    if (p.name == "coin_package") {
        CCLOG("Purchase complete: coin_package");
        _coinCount += 1000;
        _txtCoin->setString(tostr(_coinCount));
    }
    else if (p.name == "coin_package2") {
        CCLOG("Purchase complete: coin_package2");
        _coinCount += 5000;
        _txtCoin->setString(tostr(_coinCount));
    }
    else if (p.name == "remove_ads") {
        CCLOG("Purchase complete: Remove Ads");
    }

    CCLOG("Purchase Success: %s", p.id.c_str());
}

void HelloWorld::onFailure(const Product &p, const std::string &msg)
{
    CCLOG("Purchase Failed: %s", msg.c_str());

}

void HelloWorld::onCanceled(const Product &p)
{
    CCLOG("Purchase Canceled: %s", p.id.c_str());
}

void HelloWorld::onRestored(const Product& p)
{
    CCLOG("Purchase Restored: %s", p.name.c_str());
}

void HelloWorld::updateIAP(const std::vector<sdkbox::Product>& products)
{
    _iapMenu->removeAllChildren();
    _products = products;


    for (int i=0; i < _products.size(); i++)
    {
        CCLOG("IAP: ========= IAP Item =========");
        CCLOG("IAP: Name: %s", _products[i].name.c_str());
        CCLOG("IAP: ID: %s", _products[i].id.c_str());
        CCLOG("IAP: Title: %s", _products[i].title.c_str());
        CCLOG("IAP: Desc: %s", _products[i].description.c_str());
        CCLOG("IAP: Price: %s", _products[i].price.c_str());
        CCLOG("IAP: Price Value: %f", _products[i].priceValue);

        auto item = MenuItemLabel::create(Label::createWithSystemFont(_products[i].name, "sans", fontsize), CC_CALLBACK_1(HelloWorld::onIAP, this));
        item->setUserData(&_products[i]);
        _iapMenu->addChild(item);
    }

    Size size = Director::getInstance()->getWinSize();
    _iapMenu->alignItemsVerticallyWithPadding(10);
}

void HelloWorld::onProductRequestSuccess(const std::vector<Product> &products)
{
    updateIAP(products);
}

void HelloWorld::onProductRequestFailure(const std::string &msg)
{
    CCLOG("Fail to load products");
}

void HelloWorld::onRestoreComplete(bool ok, const std::string &msg)
{
    CCLOG("%s:%d:%s", __func__, ok, msg.data());
}
