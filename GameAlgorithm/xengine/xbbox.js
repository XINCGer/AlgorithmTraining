 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 包围盒类
 */
(function(win){
   //包围盒抽象类   
   var _bBox = win.BBox = Class.extend({	
	   init:function(x,y)
	   {
		   //中心坐标
		   this.x = x;
		   this.y = y;
		   //颜色
		   this.c = "red";
	   },
       isCollide:function(bbox)
	   {
		   if(this.constructor.ClassName!=bbox.constructor.ClassName)
		   {
			   throw Error("Box Type mismatch! ");
		   }
		   else
		   {
			   return this.collided(bbox);
		   }
	   },
	   collided:function(bbox)
	   {
		   throw Error("This method must be override by child class!");
	   },
	   getType:function()
	   {
		   return this.constructor.ClassName;
	   },	   
       //显示包围盒
	   show:function(ctx)
	   {
		   throw Error("This method must be override by child class!");
	   }
   });
   //圆形包围盒
   var _RBBox = win.RBBox = BBox.extend({
	   //x,y为圆心坐标，r是半径
	   init:function(x,y,r)
	   {
		   this.r = r;
		   this._super(x,y);
	   },
	   collided:function(tBox)
	   {
         var dx = this.x-tBox.x,
			 dy = this.y-tBox.y,
			 dr = this.r+tBox.r;
         return dx*dx+dy*dy<dr*dr;
	   },
	   show:function(ctx)
	   {
		 ctx.beginPath();
	     ctx.strokeStyle =this.c;
		 ctx.lineWidth = 2;
    	 ctx.arc(this.x,this.y,this.r,0,Math.PI*2);
    	 ctx.stroke();
	   }
   });
   //矩形包围盒
   var _ABBox = win.ABBox = BBox.extend({
	   init:function(x,y,hw,hh)
	   {
		   this.hh = hh;
		   this.hw = hw;
		   this._super(x,y);
	   },
	   collided:function(tBox)
	   {
         var nx = this.x-this.hw,
			 ny = this.y-this.hh,
			 mx = this.x+this.hw,
			 my = this.y+this.hh,
			 nx1 = tBox.x-tBox.hw,
			 ny1 = tBox.y-tBox.hh,
			 mx1 = tBox.x+tBox.hw,
			 my1 = tBox.y+tBox.hh;
         if(nx>mx1||mx<nx1)return false;
         if(ny>my1||my<ny1)return false;
		 return true;
	   },
	   show:function(ctx)
	   {
         ctx.beginPath();
		 ctx.lineWidth = 2;
	     ctx.strokeStyle = this.c;
    	 ctx.strokeRect(this.x-this.hw,this.y-this.hh,this.hw*2,this.hh*2);
	   }
   }); 
   //凸多边形包围盒
   var _pBBox = win.PBBox = BBox.extend({
	   //x,y是多边形中心坐标,pArr是一个顶点数组，点的坐标采用相对中心点坐标，按顺时针存放各顶点
	   init:function(x,y,pArr)
	   {
		   this.pArr = pArr;
		   this._super(x,y);
	   },     
       //转换所有顶点坐标到绝对坐标系中
	   mapToWorld:function()
	   {
		  var p = [];
          for(var i=0,len = this.pArr.length;i<len-1;i+=2)
		  {
			  p.push(this.pArr[i]+this.x,this.pArr[i+1]+this.y);
		  }
		  return p;
	   },
       collided:function(tBox)
	   {		   
		   var p1 = this.mapToWorld(),
			   p2 = tBox.mapToWorld();
		   return MathUtil.isCollide(p1,p2);
	   },
	   show:function(ctx)
	   {
		   ctx.beginPath();
		   ctx.strokeStyle = this.c;
		   ctx.lineWidth = 2;
		   //移动到第一个点
		   ctx.moveTo(this.pArr[0]+this.x,this.pArr[1]+this.y);
		   for(var i=2,len=this.pArr.length;i<len-1;i+=2)
		   {            
			   ctx.lineTo(this.pArr[i]+this.x,this.pArr[i+1]+this.y);
		   }
		   ctx.closePath();
		   ctx.stroke();
	   }
   })
   _bBox.ClassName = "BBox";
   _RBBox.ClassName = "RBBox";
   _ABBox.ClassName = "ABBox";
   _pBBox.ClassName = "PBBox";
   //注册类到类工厂中
   ClassFactory.regClass(_bBox.ClassName,_bBox);
   ClassFactory.regClass(_RBBox.ClassName,_RBBox);
   ClassFactory.regClass(_ABBox.ClassName,_ABBox);
   ClassFactory.regClass(_pBBox.ClassName,_pBBox);
}(window))