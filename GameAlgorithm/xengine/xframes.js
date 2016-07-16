/*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 帧动画对象
 */
(function(win){
 //帧动画对象
   var _frames = win.Frames = Class.extend({
      init:function(name,img,duration)
	  {
         //帧动画名称
         this.name = name;
		 //帧动画每帧所持续的时间
		 this.duration = duration|50;//默认每帧持续50毫秒
		 //保存每帧位置，和持续时间信息
		 this.frames = [];
		 //对应的动画帧序列图,
		 this.img = img;		
	  },
      //添加帧数据
      add:function(x,y,w,h,img,dur)
		{
		   var dur = dur||this.duration,
               img = img||this.img;			   
		   this.frames.push([img,x,y,w,h,dur]);
		},       
      //插入帧数据
      insert:function(idx,x,y,w,h,img,dur)
		{
           var dur = dur||this.duration,
			   img = img||this.img;
		   ArrayUtil.insert(this.frames,idx,[img,x,y,w,h,dur]);
		},	 
      //移出帧数据
	  remove:function(idx)
		{
		   this.frames.removeIdx(idx);
		}, 
	  //删除所有帧
	  clear:function()
	    {
           this.frames = [];
	    },
      //获取帧数据
	  get:function(idx)
		{
		   return this.frames[idx];
		},
      //获取总数
	  getCount:function()
		{
			return this.frames.length;
		}
   });
 //帧动画集合对象,保存一组帧动画集合
   var _animations = win.Animations = Class.extend({
     init:function()
	  {
		 //保存所有动画帧
		 this.anims = {};
	  },
     //获取所有名称
     getAllNames:function()
	 {
		var ans = [];
		for(var k in this.anims)
		 {
			if(this.anims.hasOwnProperty(k))
			 {
				ans.push(k);
			 }
		 }
		return ans;
	 },
     //添加帧动画集合
     add:function(name,frames)
	 {
		 this.anims[name] = frames;
	 },
     //删除帧动画集合
     remove:function(name)
	 {
		 this.anims[name] = null;
	 },
     //清空帧动画集合
	 clear:function()
	 {  
		 this.anims = {};
	 },
     //获取当前帧动画
	 get:function(name)
	 {
		 return this.anims[name];
	 }
   })
 //帧动画控制对象 
  var _frameCtrl = win.FrameCtrl = Class.extend({
   	    init:function(processFrameFN)
		{
          //缺省动画处理函数
          function defProcessFrame()
		  {
			  //计算上一帧到现在的时间
			  this.fDur += FrameState.elapseTime*this.speed;
			  //如果超过当前帧的持续时间就切换到下一帧
			  if(this.fDur>=this.currFrames.frames[this.currFIdx][5])
				{
				   this.fDur = 0;
				   if(this.currFIdx<this.feIdx-1)
					{		
						  ++this.currFIdx;				  		
					}
				   else
					{
					   if(this.isCycle)
						{
						  this.currFIdx = this.fsIdx;
						}	
					}         
			    }         
		  }		  
		  //设置动画处理函数
		  this.processFrame = processFrameFN||defProcessFrame;		 
		},	
	    //复位所有属性
		reset:function()
		{          
		  //开始帧索引
		  this.fsIdx = 0;
		  //结束帧索引
		  this.feIdx = this.currFrames.getCount();
		  //当前运行帧索引
		  this.currFIdx = 0;
		  //是否循环
		  this.isCycle = true;
		  //当前帧已经持续的时间
		  this.fDur = 0;
		  //动画速度
		  this.speed = 1;
		},		
        //设置当前帧动画
	    setCurrent:function(name)
	    {
		  var cFrames  = this.anims.get(name);
		  if(this.currFrames!=cFrames)
			{			 
			 var oSpeed = this.speed||1;
			 this.currFrames = cFrames;
			 this.reset();
			 this.speed = oSpeed;
			}
	    },
        //获取当前帧动画
		getCurrent:function()
	    {
			return this.currFrames;
		},
        //设置frames
		setAnims:function(animations,currAnimName)
		{
          this.anims = animations; 
          currAnimName = currAnimName||"def";
		  //设置当前动画帧集
		  this.setCurrent(currAnimName);
		},
		getCurrFrameIdx:function()
		{
		   return this.currFIdx;
		},
        //获取当前帧
		getCurrFrame:function()
		{
		   return this.currFrames.get(this.currFIdx);
		},
        //获取下一帧
		getNextFrame:function()
		{
		   this.processFrame();
		   return this.currFrames.get(this.currFIdx);
		},
        //是否到了最后一帧 
		isLastFrame:function()
	    {
			return this.currFIdx == this.currFrames.frames.length-1;
		},
		//是否到了第一帧 
		isFirstFrame:function()
	    {
			return this.currFIdx == 0;
		}
	})
//类名称
_frames.ClassName = "Frames";
_frameCtrl.ClassName ="FrameCtrl";
_animations.ClassName = "Animations"
//注册类到类工厂中
ClassFactory.regClass(_frames.ClassName,_frames);
ClassFactory.regClass(_frameCtrl.ClassName,_frameCtrl);
ClassFactory.regClass(_animations.ClassName,_animations);
}(window))