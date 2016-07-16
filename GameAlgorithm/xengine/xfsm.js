 /*!
 * xengine
 * Copyright 2012 xiangfeng
 * Released under the MIT license
 * Please contact to xiangfenglf@163.com if you hava any question 
 * 游戏状态机类
 */
 (function(win){
	  //状态管理类
	  var _StateContext = win.StateContext = Class.extend({
		  init:function(owner)
		  {
			  //和该状态类关联的对象
			  this.owner = owner;
			  this.states={};
			  this.currState = null;
		  },
		  changeState:function(type)
		  {
              this.currState&&this.currState.exit();
			  this.currState = this.states[type];
			  this.currState.enter();
		  },
		  getState:function(type)
		  {
			  return this.states[type];
		  },
		  //注册一个状态类
		  regState:function(state)
		  {
			  this.states[state.type] = state;
			  return this;
		  },
          //注销一个状态类
		  unRegState:function(type)
          {
             if(this.states[type]!=null&&this.currState!=this.states[type])
			  {
				 delete this.states[type];
			  }
		  },
		  unRegAll:function()
          { 
			  this.currState = null;
              this.states = {};
		  },
          //该方法在游戏主循环中使用
		  update:function()
		  {
              this.currState.change();
              this.currState.update(); 
		  }
	  })
      //状态抽象类
	  var _state = win.State = Class.extend({
		  init:function(type,context)
		  {			  
			  this.ctx = context;
			  this.type = type;
		  },
		  //调用context changeState方法转换到其他状态
		  change:function()
		  {
              return;
		  },
		  //当前状态的活动
          update:function()
		  {
			  return;
		  },
          //进入该状态时执行
	      enter:function()
		  {
			  return true;
		  },
          //退出状态执行
		  exit:function()
          {
			  return;
		  }
	  })
 }(window))