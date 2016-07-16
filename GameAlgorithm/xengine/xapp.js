 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏主体框架类
 */
(function(win){
   //简单的程序事件监听器
   var _appEventListener = win.AppEventListener = EventListener.extend({
	   init:function(param)
	   {
		   //监听器是否生效
		   this.enabled = true;
		   param=param||{};
		   this.onBeforeRender = param["beforeRender"]||this.onBeforeRender;		   
           this.onAfterRender = param["afterRender"]||this.onAfterRender;
	   },
       //游戏主循环执行渲染操作前触发
       onBeforeRender:function(){return true;},
       //游戏主循环执行渲染操作后触发
       onAfterRender:function(){return true;}
   });

   var _game = win.Game = Class.extend({
     //保存所有的监听器
	 listeners:[],
	 //场景管理器
	 sceneManager:null,
     //初始化方法
	 init:function()
	 {	   
	   this.sceneManager = new SceneManager();
	   this.paused = false;
	 },
     //添加监听器
	 addListener:function(ln)
     {
       this.listeners.push(ln);
	 },
     //清空监听器列表
     clearListener:function()
     {
	   this.listeners.length = 0;
     },
     //游戏主循环
     mainloop:function()
	 {
	  //执行游戏主循环
      var ltns = this.listeners;
	  //触发监听器渲染前事件
	  for(var i=0,len = ltns.length;i<len;i++)
		{
		  ltns[i].enabled&&ltns[i].onBeforeRender();
		} 
	  //获取当前场景，更新，并渲染
      var scene = this.sceneManager.getCurrentScene();
	  if(scene)
	  {
	    scene.update();
	    scene.render();
	  }
      //触发监听器渲染后事件	  
	  for(var i=0;i<len;i++)
	   {
		  ltns[i].enabled&&ltns[i].onAfterRender();
	   }
	 },
	 //执行游戏
	 run:function(fps)
	 {     
	   //设定fps默认为60帧/秒 
	   fps = fps||60;
       var self = this,
	       spf = (1000/fps)|0;
	   //开启帧数跟踪
	   FrameState.start();
       self.tHand = setInterval(function(){         
          //更新帧状态
          FrameState.update();	
		  if(!self.paused)
		   {
			  self.mainloop();
		   }
	   },spf); 
	 },
     //暂停游戏
	 pause:function()
	 {
		 this.paused = true;
	 },
	 //终止游戏
	 stop:function()
	 {
	   clearInterval(this.tHand);
	 }
   });
}(window))