/*
* Player类
*/
(function(){
  //从引擎的RenderObj继承
   Player = Sprite.extend({  
   init:function()
   {
	 this.path = null;
	 this.state = -1;
	 this.co = null;
	 this.nco = null;
	 this.step = 0;
     this._super();
   },
   //按路经移动
   startMove:function(path)
   { 
     this.path = path;
	 this.state = 0;
   },
   //重写update
   update:function()
   {	 
     if(this.state==0)
	 {		
		if(this.path!=null&&this.path.length>0)
		{
			var next = this.path.pop();
            //获取下一个坐标
			this.nco = TGame.map.mapPosToSC(next.x,next.y);			
		    //获取行动的步数
            var sx = this.nco[0]-this.x,sy = this.nco[1]-this.y;
			this.step = (sx!=0)?sx:sy;			
			this.step = Math.abs(this.step)/10;
			this.dx = (sx>0)?10:(sx==0?0:-10);
            this.dy = (sy>0)?10:(sy==0?0:-10);
            this.state = 1;
		}
        else
		{
			this.state = 2;
		}
	 }
    if(this.state==1)
	  {
		 if(this.step>0)
		  {
			 if(this.step<1)
			 {
				 this.dx = this.dx*this.step|0;
				 this.dy = this.dy*this.step|0;
			 }
  			 this.move(this.dx,this.dy);			 			
			 this.step-=1;             		 			 
		  }		 
		 else
		  {			 
			 this.state = 0;
		  }		           
	  }
    if(this.state!=1)
	 {
        this.dx = this.dy = 0;
		this.ldx = this.ldy =0;
	 }
	
   }
  });
  Player.ClassName = "Player";
  //注册Ball类
  ClassFactory.regClass(Player.ClassName,Player);
}())