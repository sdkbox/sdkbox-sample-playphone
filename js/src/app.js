
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        cc.MenuItemFont.setFontName('arial');
        cc.MenuItemFont.setFontSize(42);

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite(res.Logo_png);
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemFont("QUIT", function() {
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
        var self = this;
        sdkbox.IAP.init();
        sdkbox.IAP.setDebug(true);
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
                cc.log("Purchase successful: " + product.name)

                if (product.name == "coin_package") {
                    self.coins += 1000;
                    self.txtCoin.setString(self.coins.toString());
                } else if (product.name == "coin_package2") {
                    self.coins += 5000;
                    self.txtCoin.setString(self.coins.toString());
                }
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

                    var productName = products[i].name;
                    var btn = new cc.MenuItemFont(productName);
                    btn.name = productName;
                    btn.setCallback(function (sender) {
                        cc.log("purchase: " + sender.name);
                        sdkbox.IAP.purchase(sender.name);
                    }, null);
                    self.menuIAP.addChild(btn);
                }
                self.menuIAP.alignItemsVerticallyWithPadding(5);
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
                cc.log("Failed to get products");
            }
        });

        sdkbox.PluginAchievement.init();
        sdkbox.PluginLeaderboard.init();
        sdkbox.PluginLeaderboard.setListener({
            onComplete: function(leaderboard) {
                console.log("[IAP] fetch leaderbaord data complete " + leaderboard);
            },
            onFail: function() {
                console.log("[IAP] fetch leaderboard data failed");
            }
        });

        var LEVEL_LEADER_BOARD_ID = "1552";
        var SOLDIER_ACHIEVEMENT_ID =  "3724";

        var size = cc.winSize;
        var menu = new cc.Menu(
            new cc.MenuItemFont("load products", function() {
                sdkbox.IAP.refresh();
            }),
            new cc.MenuItemFont("restore products", function() {
                sdkbox.IAP.restore();
            }),
            new cc.MenuItemFont("update leaderboard random [1,100]", function() {
                var score = Math.floor(Math.random()*99) + 1;
                sdkbox.PluginLeaderboard.submitScore(LEVEL_LEADER_BOARD_ID, score);
            }),
            new cc.MenuItemFont("get leaderboard", function() {
                sdkbox.PluginLeaderboard.getLeaderboard(LEVEL_LEADER_BOARD_ID);
            }),
            new cc.MenuItemFont("achievement test", function() {
                sdkbox.PluginAchievement.unlock(SOLDIER_ACHIEVEMENT_ID);
            })
            );

        menu.x = size.width / 2;
        menu.y = size.height - 140;
        menu.alignItemsVerticallyWithPadding(5);
        this.addChild(menu);

        this.menuIAP = new cc.Menu();
        this.addChild(this.menuIAP);

        this.coins = 0;
        this.txtCoin = new cc.LabelTTF("0", "sans", 32);
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

