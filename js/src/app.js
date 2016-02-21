
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.IAP.init();
        sdkbox.IAP.setDebug(true);
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
                cc.log("Purchase successful: " + product.name)
            },
            onFailure : function (product, msg) {
                //Purchase failed
                //msg is the error message
                cc.log("Purchase failed: " + product.name + " error: " + msg);
            },
            onCanceled : function (product) {
                //Purchase was canceled by user
                cc.log("Purchase canceled: " + product.name);
            },
            onRestored : function (product) {
                //Purchase restored
                cc.log("Restored: " + product.name);
            },
            onProductRequestSuccess : function (products) {
                self.menuIAP.removeAllChildren();
                //Returns you the data for all the iap products
                //You can get each item using following method
                for (var i = 0; i < products.length; i++) {
                    cc.log("================");
                    cc.log("name: " + products[i].name);
                    cc.log("price: " + products[i].price);
                    cc.log("================");

                    (function() {
                        var name = products[i].name;
                        var btn = new cc.MenuItemFont(name, function() {
                            cc.log("purchase: " + name);
                            sdkbox.IAP.purchase(name);
                        });
                        self.menuIAP.addChild(btn);
                    }());
                }
                self.menuIAP.alignItemsVerticallyWithPadding(5);
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
                cc.log("Failed to get products");
            }
        });

        var LEVEL_LEADER_BOARD_ID = "1434";
        var SOLDIER_ACHIEVEMENT_ID =  "3622";

        var size = cc.winSize;
        var menu = new cc.Menu();

        menu.addChild(new cc.MenuItemLabel(new cc.Label.createWithSystemFont("load products", "sans", 24), function() {
            sdkbox.IAP.refresh();
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.Label.createWithSystemFont("restore purchase", "sans", 24), function(){
            sdkbox.IAP.restore();
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.Label.createWithSystemFont("update leaderboard random [1,100]", "sans", 24), function(){
            var score = Math.round(Math.rand() * 100);
            sdkbox.PluginLeaderboard.submitScore(LEVEL_LEADER_BOARD_ID, score);
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.Label.createWithSystemFont("get leaderboard", "sans", 24), function(){
            sdkbox.PluginLeaderboard.getLeaderboard(LEVEL_LEADER_BOARD_ID);
        }));
        menu.addChild(new cc.MenuItemLabel(new cc.Label.createWithSystemFont("achievement test", "sans", 24), function(){
            sdkbox.PluginAchievement.unlock(SOLDIER_ACHIEVEMENT_ID);
        }));

        menu.x = size.width / 2;
        menu.y = size.height - 140;
        menu.alignItemsVerticallyWithPadding(5);
        this.addChild(menu);

        this.menuIAP = new cc.Menu();
        this.addChild(this.menuIAP);

        this.txtCoin = new cc.Label("0", "sans", 32);
        this.txtCoin.x = size.width / 2;
        this.txtCoin.y = 120;
        this.addChild(this.txtCoin);

    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

