(function(win){
	var _Game = Game.extend({
		map:null,
	    player:null,
	    selPoint:null,
		init:function()
		{
		  this._super();
	      var scm = this.sceneManager; 
	      //创建场景
          var x = (document.body.clientWidth-500)*0.5;
	      var sc = scm.createScene([{"x":x,"w":500,"h":400,"name":"main"}]);
		  this.loadRes(sc);
		},
		 //加载资源
	    loadRes:function(scene)
	    {
		  var self = this;
		  ResManager.loadRes("data/res.json",function(){
			//创建精灵
			self.initSprite();
			//开始飞奔
			self.run(60); 
		  });      
	    }, 	
	    initSprite:function()
	    {
           var sc = this.sceneManager.getScene("main");	
		   var r = 5,c=6;		  
		   //创建地图
		   this.map = sc.createRObj(Map.ClassName,[r,c,"bar",32,32]);
           this.map.reset(); 
		   //创建主角
		   this.player =  sc.createRObj(Player.ClassName);
		   var anims = ResManager.getAnimationsByName("sprite","bul0");
		   this.player.setAnims(anims);
		   this.player.w = 32;
		   this.player.h = 32;		   
		   var p = this.map.mapPosToSC(1,1);
		   this.player.moveTo(p[0],p[1]);
		   //创建选择点
           this.selPoint = sc.createRObj(Sprite.ClassName);
           this.selPoint.setAnims(ResManager.getAnimationsByName("sprite","bul1"));
		   this.selPoint.w = this.selPoint.h = 16;
		   this.selPoint.moveTo(p[0],p[1]);
		} 
	})
   //定义全局TGame
   win.TGame = new _Game();
   //定义鼠标事件 
   Mouse.sDLG("down",function(e){
	   //获取游戏窗口坐标
	   var sc = TGame.sceneManager.getScene("main");
	   var gx = sc.x,
           gy = sc.y,
		   mx = Mouse.gX(),
		   my = Mouse.gY();
	   //转换鼠标坐标到游戏窗口坐标系
	   var cd = MathUtil.mapSToCoord(mx,my,gx,gy);
       var cd1 = TGame.map.mapSCPos(cd[0],cd[1]);
	   var cd2 = TGame.map.mapPosToSC(cd1[0],cd1[1]);	   
	   var start = TGame.map.mapSCPos(TGame.player.x,TGame.player.y);
	   //计算路经
	   var path = TGame.map.findPath(start,cd1);
	   if(path!=null)
	   {
		   TGame.selPoint.moveTo(cd2[0],cd2[1]);
		   TGame.player.startMove(path);
	   }	   
   });
}(window))