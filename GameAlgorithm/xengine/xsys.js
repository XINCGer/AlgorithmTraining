 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏系统类
 */
(function(win){
   //游戏状态类
   var _FState = win.FrameState ={
     //最大帧数
     maxFrame:0,
     //最小帧数
	 minFrame:9999,
     //即时帧数
     currFrame:0,
     //当前时间
	 currTime:0,
     //每帧流逝的时间
	 elapseTime:0,
     //用于统计每秒开始时间
     _sTime:0,
     //统计每秒总帧数
     _sTFrame:0,
     //启动帧状态检测器
	 start:function()
	 {
        this.currTime = this._sTime = new Date();        
	 },    
     //每帧在游戏循环前调用此方法，更新和计算帧数
     update:function()
	 {
        var fTime = new Date();
		if(fTime-this._sTime>=1000)
		{
			this.currFrame = this._sTFrame;
		    this.maxFrame = (this.currFrame>this.maxFrame)?this.currFrame:this.maxFrame;
            this.minFrame = (this.currFrame<this.minFrame)?this.currFrame:this.minFrame;           
			this._sTFrame = 0;   
			this._sTime = fTime;
		}
		else
		{
			++this._sTFrame;
		}		
		this.elapseTime = fTime-this.currTime;
		this.currTime = fTime;
	 }
   };
  //游戏IO
  //鼠标类
   win.Mouse=(function(){
   var _M = {
	   x:0,
	   y:0,  
       ox:0,
	   oy:0,
	   w:0,//鼠标中键滚动次数
	   bs:[0,0,0],//鼠标状态,
	   target:null,
	   isMoveCacheEnable:false,//是否启用记录移动点缓存
	   cache:[],//记录鼠标移动点缓存
	   dlgEvent:{"up":null,"down":null,"click":null,"dbclick":null,"move":null,"wheel":null}//代理事件处理
	 };	   
   //默认记录30个点的缓存
   var _MAX_POINT_CACHE = 60;
   var eWeelDelta = 120;
   //设置目标
   function setTarget(e)
   {
	 _M.target = e.target;
   }
   //设置鼠标位置
   function setMPos(e)
   {
	 _M.x = e.pageX;
	 _M.y = e.pageY;
   }
   //设置鼠标按键状态
   function setMBtnState(e,flag)
   {
	 _M.bs[e.button] = flag;
   }
   //添加点到Cache中
   function addToMPCache(x,y)
   {
	 if(_M.cache.length>_MAX_POINT_CACHE)
	 {
	   _M.cache.shift();
	   _M.cache.shift();
	 }
	 _M.cache.push(x);
	 _M.cache.push(y);
   }
   //获取缓冲区中最前的坐标，缓冲模式下用
   function get()
   { 
     var x = _M.cache.shift(),
		 y = _M.cache.shift();
     return [x,y];
   }
   //清除所有缓存
   function clearCache()
   {
	  _M.cache=[];
   }
   //设置事件代理
   function setDelegatedEvent(eName,fn)
   {
	   _M.dlgEvent[eName] = fn;
   }
   //删除事件代理
   function delDelegatedEvent(eName)
   {
	   _M.dlgEvent[eName] = null;
   }
   //设置是否可用
   function setEnabled(flag)
   {
	 if(flag)
	  {
        document.oncontextmenu=function(){return false}; 
        document.onmousemove = doMove;
		document.onmousedown = doDown;
		document.onmouseup = doUp;
		document.onclick = doClick;
		document.ondblick = doDBClick;
		document.onmousewheel = doWheel;
	  }
	 else
	  {
        document.onmousemove = null;
		document.onmousedown = null;
		document.onmouseup = null;
		document.onclick = null;
		document.ondblick = null;
		document.onmousewheel = null;
	  } 	 		 
   }
   function doMove(e)
   {
	 e.preventDefault();
	 setMPos(e);
	 setTarget(e);
	 if(_M.isMoveCacheEnable)
	 {
	   addToMPCache(_M.x,_M.y);
	 }
	 _M.dlgEvent.move&&_M.dlgEvent.move(e);
   }
   function doDown(e)
   {
     //e.preventDefault();
	 setMBtnState(e,1);
	 setTarget(e);
	 _M.ox = e.pageX;
     _M.oy = e.pageY;
     _M.dlgEvent.down&&_M.dlgEvent.down(e);
   }
   function doUp(e)
   {
	 setMBtnState(e,0);
	 setTarget(e);
	 _M.dlgEvent.up&&_M.dlgEvent.up(e);
   }
   function doClick(e)
   {	   
	 _M.dlgEvent.click&&_M.dlgEvent.click(e);
   }
   function doDBClick(e)
   {
	 _M.dlgEvent.dbclick&&_M.dlgEvent.dbclick(e);  
   }
   function doWheel(e)
   {
	 this.w+=(e.wheelDelta>=eWeelDelta)?1:-1;
     _M.dlgEvent.doWheel&&_M.dlgEvent.doWheel(e);  
   }
   //初始化
   setEnabled(true);
   return {
	  gTarget:function(){return _M.target;},
	  gPos:function(v3){v3.x = _M.x;v3.y = _M.y;v3.z = _M.w},
	  gX:function(){return _M.x},
      gY:function(){return _M.y},
      gW:function(){return _M.w},
	  gBtnState:function(btn){return _M.bs[btn]; },
	  gXOff:function(){return _M.x-_M.ox},
      gYOff:function(){return _M.y-_M.oy},
	  gCPT:function(){ return get();},
	  cCHE:function(){ clearCache();},
      sDLG:function(eName,fn){setDelegatedEvent(eName,fn);},
      dDLG:function(eName){delDelegatedEvent(eName);},
	  sMode:function(mode){_M.isMoveCacheEnable = (mode===1);}//0:立即模式，1:缓冲模式
	};
  }());
  //键盘类
  win.Key = (function(){
	var _K = {  
	  A:65,
	  B:66,
	  C:67,
	  D:68,
	  E:69,
	  F:70,
	  G:71,
	  H:72,
	  I:73,
	  J:74,
	  K:75,
	  L:76,
	  M:77,
	  N:78,
	  O:79,
	  P:80,
	  Q:81,
	  R:82,
	  S:83,
	  T:84,
	  U:85,
	  V:86,
	  W:87,
	  X:88,
	  Y:89,
	  Z:90,
	  N0:48,
	  N1:49,
	  N2:50,
	  N3:51,
	  N4:52,
	  N5:53,
	  N6:54,
	  N7:55,
	  N8:56,
	  N9:57,
	  LEFT:37,
	  RIGHT:39,
	  UP:38,
	  DOWN:40,
	  ENTER:13,
	  SPACE:32,
	  TAB:9,
	  SHIFT:16,
	  ALT:18,
	  CTRL:17,	  
	  //记录键盘缓冲最大数
	  MAX_KEY_CACHE:20,
	  //记录键盘状态
	  states:new Array(255),
	  cache:[],
      //事件代理对象
      dlgEvent:{"up":null,"down":null},
	  isEnableCache:false,
	  //设置事件代理
      setDLG:function(eName,fn)
      {
	   this.dlgEvent[eName] = fn;
      },
      //删除事件代理
      delDLG:function(eName)
      {
	   this.dlgEvent[eName] = null;
      },
      //设置是否可用
	  setEnabled:function(flag)
	  {
		  var self = this;
		  if(flag)
		  {
		   var st = this.states;
		   this.clearKeyStates();
		   this.sMode(0);
		   document.onkeydown = function(e)
		   {
               st[event.keyCode] = 1; 
			   if(self.isEnableCache)
			   {
				if(self.cache.length>MAX_KEY_CACHE)
				 {
				   self.cache.shift();
				 }
				 self.cache.push(e.keyCode);
			   }
			   self.dlgEvent.down&&self.dlgEvent.down(e);
		   };
		   document.onkeyup = function(e)
		   {
              st[e.keyCode] = 0;  
              self.dlgEvent.up&&self.dlgEvent.up(e);
		   }		  
		  }
		  else
		  {
            document.onkeydown = null;
			document.onkeyup = null;
		  }
	  },
      //判断是否按键
	  pressed:function(key)
	  {
		 return this.states[key];
	  },
	  //获取缓冲区中最前的按键
	  get:function()
      {
         return this.cache.shift();
	  },
      //按了keys数组中任何键
	  pAny:function(keys)
	  {
		var result = false;
		for(var  i=0;i<keys.length;i++)
		{
		   if(this.states[keys[i]])
			{
			   result = true;
			   break;
		    }
		}
		return result;
	  },
      //按下所有键,state 1:down 0:up
	  pAll:function(keys,state)
	  {
        var result = true;
		for(var  i=0;i<keys.length;i++)
		{
		   if(this.states[keys[i]]==!state)
			{
			   result = false;
			   break;
		    }
		}
		return result; 
	  }, 
	  clearKeyStates:function()
	  {
		 for(var i =0;i<255;i++)
		 {
		   this.states[i]=0;
		 }
	  },
	  clearCache:function()
      {
		  this.cache = [];
	  },
	  sMode:function(mode)
	  {
		 this.isEnableCache = (mode===1);
	  }
	}
	//初始化
	_K.setEnabled(true);
	return _K;
  }());
}(window))