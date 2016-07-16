function XMusic()
{
	//associate html Element
	this.hE = null;
	this.autoPlay = false;
	this.isLooped = true;
	this.time = 0;
	this.eType = "music";
	 //index in pool ,if it is from pool;
    this.poolIdx = -1;
   // released to pool
    this.isReleased = true;
}
XMusic.prototype =
{
   play:function(immeFlag,looped,time)
   {
	   var lp = nullIf(looped,false);
	   var f = nullIf(immeFlag,true);
	   if(f)
	   { 
		   this.stop();
	   }
	   try
	   {
		   if(lp)
		    {
			  this.hE.loop="loop";
		    }
		    this.hE.play();
	   }
	   catch (err)
	   {
	   }      
   },
   setStartTime:function(time)
   {
	   this.hE.currentTime = time;
   },
   pause:function()
   {
	   this.hE.pause(); 
   },
   stop:function()
   {
	   try
	   {
		this.pause();
	    this.setStartTime(0);
	   }
	   catch (err)
	   {
	   }	   
   },
   reset:function()
   {
	   this.stop();
   },
   //
   loadFromFile:function(fileURL)
   {         
	  var self = this;	 
	  if(!this.isLoaded)
	   {  
		  var hE = $("<audio></autio>")[0];
		  hE.src=fileURL;
		  this.hE = hE;
		  this.src = fileURL;	
		  self.isLoaded = true;
	   }	  
   }   
}
XMusic.extends(Resource);