/*
* 地图
*/
(function(){
   //从引擎的RenderObj继承
   Map = Sprite.extend({   
   init:function(r,c,wName,ww,wh)
   {
	   this.r = r;
	   this.c = c;
	   this.ww = ww;
	   this.wh = wh
	   this.wName = wName;
	   this.offX = 0;
	   this.offY = 0;
	   this.mapData = null;
	   this.maze = null;
	   this._super();	  
   },  
   reset:function()
   {
	   var sc = this.owner;
	   var maze = MapUtil.primMaze(this.r,this.c);
	   this.maze = maze;
	   this.mapData = MapUtil.convertArrToAS(maze);
	   this.offX = (sc.w-this.ww*(2*this.c+1))*0.5+(this.ww*0.5)
	   this.offY = (sc.h-this.wh*(2*this.r+1))*0.5+(this.wh*0.5);
	   //创建外墙
	   for(var i=0;i<maze.length;i++)
	   {
		  var m = maze[i];
		  for(var j=0;j<m.length;j++)
		   {
			  if(maze[i][j]==1)
			   {
				  var bar = sc.createRObj(Sprite.ClassName);					  					  
				  var anims = ResManager.getAnimationsByName("sprite",this.wName);
				  bar.setAnims(anims);
				  bar.w = this.ww;
				  bar.h = this.wh;	                   
				  bar.moveTo(this.offX+j*this.ww,this.offY+i*this.wh);
			   }
		   }
	   }
   }, 
   //定位屏幕坐标到数组位置
   mapSCPos:function(x,y)
   {
	  return [(y-this.offY+this.wh*0.5)/this.wh|0,(x-this.offX+this.ww*0.5)/this.ww|0];
   },
   //定位数组位置到屏幕坐标
   mapPosToSC:function(r,c)
   {
      return [this.offX+this.ww*c|0,this.offY+this.wh*r|0];
   },
   //查找路经
   findPath:function(start,end)
   {
	  var m = MapUtil.convertArrToAS(this.maze);
	  var p = MapUtil.findPathA(m,start,end,m.length,m.length);
	  return p; 
   },   
   render:function(ctx)
   {
     return true;
   }
  });
  Map.ClassName = "Map";
  //注册CObj类
  ClassFactory.regClass(Map.ClassName,Map);
}())