 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏场景类
 */
(function(win){
   //场景监听器
   var _sceneEventListener = win.SceneEventListener = EventListener.extend({
	   init:function(param)
	   {
		   //监听器是否生效
		   this.enabled = true;
		   param=param||{};
		   this.onBeforeRender = param["beforeRender"]||this.onBeforeRender;
           this.onAfterRender = param["afterRender"]||this.onAfterRender;
	   },
       //场景渲染操作前触发
       onBeforeRender:function(scene){return true;},
       //场景渲染操作后触发
       onAfterRender:function(scene){return true;}
   });
   //场景类   
   var _scene = win.Scene = Class.extend({
	   init:function(arg)
	   {
		  arg = arg||{};
          //场景名称 
          this.name = arg.name||("Unnamed_"+(++_scene.SID)); 
		  //位置信息
		  this.x = arg.x||0;
		  this.y = arg.y||0;
		  this.w = arg.w||320;
		  this.h = arg.h||200;
		  this.color = arg.color||"black";
		  //场景容器
		  this.holder = $("<div id='sc_"+this.name+"' style='position:absolute;overflow:hidden;left:0px;top:0px'></div>")
		  //绑定的canvas元素,以后的精灵都在这个canvas上进行绘制
		  this.cvs = $("<canvas id='cv_"+this.name+"' style='z-index:-1;position:absolute;left:0px;top:0px'></canvas>");
		  this.ctx = this.cvs[0].getContext("2d");
		  this.setPos();
		  this.setSize();
		  this.setColor(this.color);
		  this.holder.append(this.cvs);
		  $(document.body).append(this.holder);
		  //保存所有的监听器
	      this.listeners = [],
		  //记录所有的渲染对象
		  this.rObjs = [];
		  //命名的渲染对象，便于根据名称快速查找对象
		  this.namedRObjs = {};
	   },
	   //创建渲染对象
	   createRObj:function(className,arg)
       {		
		  className = className||"RenderObj"; 
          var obj =  ClassFactory.newInstance(className,arg);
		  this.addRObj(obj);
		  return obj;
	   },
       //添加到rObjs中
	   addRObj:function(renderObj)
       {
		  renderObj.owner = this;
		  this.rObjs.push(renderObj);
          this.namedRObjs[renderObj.name] = renderObj;
	   },
	   //删除对象
	   removeRObj:function(renderObj)
       {
		 this.removeRObjByName(renderObj.name);
	   },
       //根据名称设置对象移除标记
	   removeRObjByName:function(name)
       {		  
          this.namedRObjs[name]&&(this.namedRObjs[name].canRemove=true||true);
	   },
       //移除所有置可移除标记的对象
	   removeAllCanRemove:function()
       {
         for(var i=0;i<this.rObjs.length;i++)
		   {
			    var o = this.rObjs[i];
			    if(o.canRemove){
                   delete this.namedRObjs[o.name];  
				   this.rObjs.splice(i,1);
			   }
		   }
	   }, 
       //根据名称查找对象
	   getRObjByName:function(name)
	   {
		   return this.namedRObjs[name];
	   },
       //清除所有渲染对象
       clearRObj:function()
       {
          this.rObjs = [];
		  this.namedRObjs = {};
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
	   //更新场景
	   update:function()
       {
		   var o = [];
		   for(var i = 0;i<this.rObjs.length;i++)
		   {
			   this.rObjs[i].update();			  
		   }
		   this.removeAllCanRemove(); 
	   },     
	   //执行渲染	   
	   render:function()
       {
		   var ltns = this.listeners;
		   //先清除场景，再渲染
           this.clear(); 
		   //执行渲染前监听器
           for(var i=0,len = ltns.length;i<len;i++)
			{
		       ltns[i].enabled&&ltns[i].onBeforeRender(this);
		    } 		
		   //排序
		   this.sortRObj();
		   this.renderRObj();
		   //执行渲染后监听器         
		   for(var i=0;i<len;i++)
		    {
			  ltns[i].enabled&&ltns[i].onAfterRender(this);
		    }
	   },
	   //渲染所有对象
	   renderRObj:function()
       {
		   for(var i = 0,len = this.rObjs.length;i<len;i++)
		   {

			   this.ctx.save();
			   this.rObjs[i].isVisible&&this.rObjs[i].render(this.ctx);
			   this.ctx.restore();
		   }
	   },
       //按zIdx排序所有渲染对象，渲染按数字越小越先渲染
	   sortRObj:function()
       {
          this.rObjs.sort(function(o1,o2){
			  return o1.zIdx-o2.zIdx;
		  })
	   },
	   //设置位置
	   setPos:function(x,y)
	   {
		   this.x = x||this.x;
		   this.y = y||this.y;
		   this.holder.css("left",this.x).css("top",this.y);
	   },
       //设置大小
       setSize:function(w,h)
	   {
		   this.w = w||this.w;
		   this.h = h||this.h;
		   this.holder.css("width",this.w).css("height",this.h);
		   this.cvs.attr("width",this.w).attr("height",this.h);
	   },       
       //设置canvas背景
	   setColor:function(color)
	   {		   
		   this.color = color||"black";
           this.holder.css("background-color",this.color);
	   },
	   //清除canvas背景
	   clear:function()
       {
          this.ctx.clearRect(0,0,this.w,this.h);
	   },
       //显示
	   show:function()
	   {
		   this.holder.show();
	   },
       //隐藏
	   hide:function()
       {
		   this.holder.hide();
	   },
	   fadeOut:function(time,fn)
       {
		   this.holder.fadeOut(time,fn);
	   },
       fadeIn:function(time,fn)
       {
		   this.holder.fadeIn(time,fn);
	   },
	   //设置背景,pattern:0(居中),1(拉伸),默认(平铺)
	   setBGImg:function(imgURL,pattern)
       {
          this.holder.css("background-image","url("+imgURL+")");
		  switch(pattern)
		  {
			  case 0:
                  this.holder.css("background-repeat","no-repeat");
			      this.holder.css("background-position","center");
				  break;
			  case 1:
                  this.holder.css("background-size",this.w+"px "+this.h+"px ");
				  break;
		  }
	   },
       //清除相关所有资源
	   clean:function()
       {
		  this.listeners = null;
		  this.cvs.remove();
		  this.holder.remove();
		  this.cvs = this.holder = this.ctx = null;
	   }
   });
   //记录scene编号
   _scene.SID = 0;
   _scene.ClassName = "Scene";
   //注册类到类工厂中
   ClassFactory.regClass(_scene.ClassName,_scene);
}(window))