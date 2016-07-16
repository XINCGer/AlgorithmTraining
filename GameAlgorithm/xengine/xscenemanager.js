 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏场景管理类
 */
(function(win){
   //场景管理类   
   var _sceneman = win.SceneManager = Class.extend({
	   init:function(param)
	   {
          //以命名方式保存,便于快速通过名称获取
		  this.namedScenes = {};
		  //以堆栈方式保存所有场景，最后的元素为栈顶
		  this.scenes = [];		  
	   },
       //创建新的场景,通过类名和参数创建,因为scene可能有自己的子类,需要注意的是arg是必须要是数组形式
	   createScene:function(sceneClass,args){ 			 
         var sc = null;		 
		 if(arguments.length == 1)
		 {
             sc =  ClassFactory.newInstance("Scene",arguments[0]);  
		 }
		 else{
			 sceneClass = sceneClass||"Scene"; 
             sc =  ClassFactory.newInstance(sceneClass,args);
		 }
		 this.push(sc);
		 return sc;
	   }, 
       //场景重排序
	   sortSceneIdx:function()
	   {
		   for(var i=0,len=this.scenes.length;i<len;i++)
		   {
			   var sc = this.scenes[i];
			   sc.holder.css("z-index",i);
		   }
	   },
       //压入scene场景
       push:function(scene)
	   {
		   if(!this.getScene(scene.name))
		   {
			   this.scenes.push(scene);
			   this.namedScenes[scene.name] = scene;
			   this.sortSceneIdx();
		   }		  
	   },
       //移除顶部场景
	   pop:function()
	   {
		  var sc = this.scenes.pop();
          if(sc!=null)
		  {
             sc.clean();			 
			 delete this.namedScenes[sc.name]; 
		     this.sortSceneIdx();
		  }		 
	   }, 
	   //删除场景
	   remove:function(name)
       {
		  var sc = this.getScene(name);
          if(sc!=null)
		  {
             sc.clean();		
			 delete this.namedScenes[name]; 
			 ArrayUtil.removeFn(this.scenes,function(s){
				 return s.name===name;
			 })
		     this.sortSceneIdx();
		  }		  
	   },
	   //交换场景位置
       swap:function(from,to)
	   {
		 if(from>=0&&from<=this.scenes.length-1
			&&to>=0&&to<=this.scenes.length-1)
		 {
             var sc = this.scenes[from];
			 this.scenes[from] = this.scenes[to];
			 this.scenes[to] = sc;
			 this.sortSceneIdx();
		 }         
	   },
	   //获取某个场景的索引
	   getIdx:function(scene)
	   {		  
		   return scene.holder.css("z-index");		
	   },
	   //把某个场景移动到最顶部
	   bringToTop:function(scene)
	   {
         var idx = this.getIdx(scene);
		 if(idx!=this.scenes.length-1)
		 {
			 this.scenes.splice(idx,1);
			 this.scenes[this.scenes.length] = scene;	
			 this.sortSceneIdx();
		 }		 
	   },
	   //把某个场景移动到最底部
	   bringToLast:function(scene)
	   {
		 var idx = this.getIdx(scene);
		 if(idx!=0)
		 {
			 this.scenes.splice(idx,1);
			 this.scenes.splice(0,0,scene);
			 this.sortSceneIdx();
		 }		 
	   },
       //场景后移
       back:function(scene)
       {
		 var idx = this.getIdx(scene);
		 if(idx>0)
		 {
			 this.swap(idx,idx-1);
		 }		 
	   },
       //场景前移
       forward:function(scene)
       {
         var idx = this.getIdx(scene);
		 if(idx<this.scenes.length)
		 {			 
			 this.swap(idx,idx+1);
		 }		 
	   },
       //根据名称获取场景
	   getScene:function(name)
	   {
		 return this.namedScenes[name];
	   }, 
       //获取当前场景,顶部场景为当前场景
	   getCurrentScene:function()
       {
		  return this.scenes[this.scenes.length-1];
	   }, 
	   //清除所有场景
	   clearAll:function()
       {
         for(var i in this.scenes)
		 {
           this.scenes[i].clean(); 
		 }
		 this.namedScenes = {};
		 this.scenes = [];
	   }
   });
}(window))