 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏粒子效果类
 */
(function(win){
    //从引擎的Sprite继承
	var _particle = win.Particle = Sprite.extend({  
	init:function()
	{
	 //生命毫秒
	 this.life = 500;
	 //年龄
	 this.age = 0 ;
	 //开始时间 
	 this.sTime = 0 ;
	 //初始大小
	 this.sSize = 1;
	 //结束大小
	 this.eSize = 1;	
	 //是否激活
	 this.active = false;
	 this._super();
	 this.isVisible = this.active;
	},
	start:function()
	{
	   this.sTime = FrameState.currTime;
	   this.active = this.isVisible = true;
	},
	stop:function()
	{
	   this.active = this.isVisible = false;
	   this.age = 0;
	},
	update:function()
	{	         	  	  	  
	  if(this.active)
	  {
		this.age = FrameState.currTime - this.sTime;
		if(this.age>=this.life){
		  this.owner.removeRObj(this);	
		  return ;
		}        
		this._super();
	  }	  
	 }
	});
	//粒子发生器
	var _emit = win.Emit = Class.extend({
	 init:function(param,sc,pClassName,pParam)
	  {	
		 //喷射间隔时间
		 this.speed = param["speed"]||100;
		 //喷射次数,<0表示无限
		 this.times = param["times"]||-1;
		 //设定生命周期
		 this.lifeRange = param["lifeRange"]||[500,800];
		 this.sSize = param["sSize"]||1;
		 this.eSize = param["eSize"]||1;
		 this.timeRange = param["timeRange"]||999999;
		 this.maxNum = param["maxNum"]||200;
		 this.pos =  param["pos"]||[0,0]
		 this.v = param["v"]||[0,0];
		 this.vRange = param["vRange"]||[0,0];
		 this.a = param["a"]||[0,0];
		 this.aRange = param["aRange"]||[0,0];
		 this.ang = param["ang"]||0;
		 this.angRange = param["angRange"]||0;
		 this.sc = sc;
		 this.pClassName = pClassName;
		 this.pParam = pParam;
		 this.startTime = FrameState.currTime;
	  },
	 createParticle:function()
	 {
		for(var i=0;i<this.maxNum;i++)
		   {
			 var p = this.sc.createRObj(this.pClassName,this.pParam);
			 p.life = MathUtil.randInt(this.lifeRange[0],this.lifeRange[1]);
			 p.sSize = this.sSize;
			 p.eSize = this.eSize;
			 p.x = this.pos[0];
			 p.y = this.pos[1];
			 p.vx = this.a[0]+MathUtil.randRange(this.aRange[0]);
			 p.vy = this.a[1]+MathUtil.randRange(this.aRange[1]);
			 p.dx = this.v[0]+MathUtil.randRange(this.vRange[0]);
			 p.dy = this.v[1]+MathUtil.randRange(this.vRange[1]);
			 p.deg = this.ang+MathUtil.randRange(this.angRange);
			 p.start();
		   }
	 },
	//发射
	 jet:function()
	 {
		this.startTime = FrameState.currTime;
		this.createParticle();
	 },
	 //可放在游戏循环中更新
	 update:function()
	 {		
		if((this.times!=0)&&(FrameState.currTime-this.startTime>this.speed))
		 {
		   this.jet();
		 } 
		if(this.times>0)--this.times;
	 }
	})
   //记录part编号
   _particle.SID = 0;
   _particle.ClassName = "Particle";
   //注册类到类工厂中
   ClassFactory.regClass(_particle.ClassName,_particle);
}(window))