/*
$.alertModal = function(message, title){
	/*
	var html = '<div class="modal hide">'
	 + '<div class="modal-header"><a href="#" class="close" data-dismiss="modal">&times;</a><h3>' + (title || '') +'</h3></div>'
	 + '<div class="modal-body"><p>' + message + '</p></div>'
	 + '<div class="modal-footer"><a href="#" class="btn primary" data-dismiss="modal">确定</a></div>'
	+'</div>';
	return $(html).modal({keyboard:true, show:true});
	
};
*/
$.checkResponse = function(successCallback, errorCallback){
	return function(rsp, result, xhr){
		if (rsp === null)
			Callbacks.alert(xhr.responseText);
		else if(typeof rsp == 'object'){
			switch(rsp.code){
				case 0:
					(successCallback || Callbacks.successAlert)(rsp, result, xhr);//return f.run(arguments);
					break;
				case 'INVALID':
				case 'ERROR':
				default: 
					(errorCallback || Callbacks.errorAlert)(rsp, result, xhr);
			}
		}
		else
			Callbacks.alert(rsp);
			//Callbacks.errorAlert(rsp);
	}
}

$.fn.freeze = function (){
	$.each($(this).find('button[type=submit]'), function(){this.disabled = true;});
	$.each(this.find('input, select, textarea'), function(){this.readOnly = true;});
}

$.fn.unfreeze = function(){
	$.each($(this).find('button[type=submit]'), function(){this.disabled = false;});
	$.each(this.find('input, select, textarea'), function(){this.readOnly = false;});
}

$.fn.ajaxsubmit = function(successCallback, errorCallback){//这个函数，适用于各种ajax方式提交请求的form，只要在form的属性中加入onsubmit=$(this).ajaxsubmit(event,回调函数名)就可以了。
	var form = this;
	$.ajax({
	url  : this.attr('action'),
    type: this.attr('method').toUpperCase(),
    data: this.serialize(),
    beforeSend: function(){
		form.freeze();
		//form.find('span.error-message').remove();
	},
	complete: function(){form.unfreeze();},
	success: $.checkResponse(successCallback, errorCallback)
  });
}

$.fn.setFriend = function(friendId){
	var checked = $(this).attr('checked');
	if(checked == undefined){
		$(this).attr('checked',true);
		api.setFriend('select',friendId);
	}
	if(checked == 'checked'){
		$(this).attr('checked',false);
		api.setFriend('cancel',friendId);
	}
}

//msra track
$.fn.msraTrack = function(){
	var url = $(this).attr('href');
	$.get("/msra_tracklog?url=" + url);
}


var Callbacks = window.Callbacks = {
		alert:function(rsp){
			alert(rsp);
		},
		
		//
		errorAlert:function(rsp, result, xhr){
			//alert(xhr.responseText);
			//alert(rsp.errorMessage);
			//$.alertModal(rsp.errorMessage,'错误提示');
			alert(rsp.errorMessage);
		},
		successAlert:function(rsp, result, xhr){
			//alert(xhr.responseText);
			alert(rsp.response['message']);
		},
		successDoNothing:function(rsp, result, xhr){
			if(rsp.response['message'] != 'success')
				alert('no success');
		},
		redirect:function(key) {
			return function(rsp, result){
				window.location = rsp.response[key];
			}
		},
		successRedirect:function(key) {
			return function(rsp, result){
				if(rsp.response['message'] == 'success')
					window.location = rsp.response[key];
				else
					alert(rsp.response['message']);
			}
		},
		
		refresh:function(rsp, result) {
				window.location.reload(true);
		},
		
		buttonToggle:function(rsp, result){
			if(rsp.response['type'] == 'add'){
				if(rsp.response['message'] == 'success'){
					var pid = '#' + rsp.response['pid'];
					$(pid).find('.remove').show();
					$(pid).find('.add').hide();
				}
			}else if(rsp.response['type'] == 'remove'){
				if(rsp.response['message'] == 'success'){
					var pid = '#' + rsp.response['pid'];
					$(pid).find('.remove').hide();
					$(pid).find('.add').show();
				}
			}
		},
		
		judgeResult:function(rsp, result){
			if(rsp.response['message'] == 'success'){
				judge.getResult(rsp.response['solution_id']);
			}
		},
		
		hideContest:function(rsp, result){
			if(rsp.response['message'] == 'success'){
				var contestId = '#' + rsp.response['contest_id'];
				$(contestId).remove();
			}
		},
		
		showContest:function(rsp, result){
			if(rsp.response['message'] == 'success'){
				var contestId = '#' + rsp.response['contest_id'];
				$(contestId).find('#show').hide();
				$(contestId).find('#hide').show();
			}
		},
		
		addJob:function(rsp, result){
			if(rsp.response['message'] == 'success'){
				var obj = $('#JS-groupJobs').last().clone();
				$(obj).removeClass("hide");
				$(obj).find('.js-job-index').html(rsp.response['index']);
				$(obj).find('.js-job-value').val(rsp.response['job']);
				$(obj).appendTo('.js-jobs');
			}
		}
	};

var judge = {
	count:0,
	getResult:function(solution_id){
		setTimeout("api.judgeResult("+solution_id+");",4000);
	},
	callBack:function(rsp, result){
		if(rsp.response['solution_result'] == 'WT'){
			judge.count += 1;
			if(judge.count<5){
				var solution_id = rsp.response['solution_id'];
				setTimeout("api.judgeResult("+solution_id+");",8000);
			}
			else
			{	
				judge.count = 0;
				judge.commonResult('系统繁忙,请稍后再试。');
			}
		}
		else if(rsp.response['solution_result'] == 'CE')
		{
			judge.compileErrorResult("编译错误",rsp.response['compile_error_info']);
		}
		else
		{
			switch(rsp.response['solution_result']){
			case 'TLE':
				judge.commonResult('Time Limit Exceeded');
				break;
			case 'WA':
				judge.commonResult('Wrong Answer');
				break;
			case 'MLE':
				judge.commonResult('Memory Limit Exceeded');
				break;
			case 'PD':
				judge.commonResult('Problem Disabled');
				break;
			case 'OLE':
				judge.commonResult('Output Limit Exceeded');
				break;
			case 'RE':
				judge.commonResult('Runtime Error');
				break;
			case 'SE':
				judge.commonResult('System Error');
				break;
			case 'AC':
				judge.commonResult('Accepted');
				break;
			case 'RF':
				judge.commonResult('Runtime Error');
				break;
			}
		}
	},
	compileErrorResult:function(message,errorinfo){
		var html= '<div class="alert alert-error">'
			+'<h3>' + message + '</h3>'
		   	+ '<div class="ce-output">'
			+'<pre>'+ errorinfo +'</pre>'	
			+ '</div>'
	    	+'</div>';
		$('#result').html(html);
		judge.buttonStatusReset();
	},
	commonResult:function(message){
		var className = 'alert-error';
		if(message === '通过')
			className = 'alert-success';
		var html= '<div class="alert ' + className + '">'
			+'<h3>' + message + '</h3>'
		   	+ '<div class="ce-output">'	
			+ '</div>'
	    	+'</div>';
		$('#result').html(html);
		judge.buttonStatusReset();
	},
	buttonStatus:function(){
		$(".js-code-submit").button('loading');
	},
	buttonStatusReset:function(){
		$(".js-code-submit").button('reset');
	}
}

function getCookie(c_name) {
	if (document.cookie.length>0) {
		c_start=document.cookie.indexOf(c_name + "=");
		if (c_start!=-1)
		{ 
				c_start=c_start + c_name.length+1;
				c_end=document.cookie.indexOf(";",c_start);
				if (c_end==-1) c_end=document.cookie.length;
				return unescape(document.cookie.substring(c_start,c_end));
		} 
	}
	return "";
}

function setCookie(c_name,value,expiredays) {
	var exdate=new Date();
	exdate.setDate(exdate.getDate()+expiredays);
	document.cookie=c_name+ "=" +escape(value)+((expiredays==null) ? "" : ";expires="+exdate.toGMTString());
}

//test 剩余时间
$.showTime = function(){
	var time_distance,str_time;
	var int_day,int_hour,int_minute,int_second;
	time--;
	time_distance = time;
	if(time_distance>0){
		int_day = Math.floor(time_distance/86400);
		time_distance-=int_day*86400;
		int_hour=Math.floor(time_distance/3600)
		time_distance-=int_hour*3600;
		int_minute=Math.floor(time_distance/60)
		time_distance-=int_minute*60;
		int_second=Math.floor(time_distance/1)
		if(int_hour<10)
		   int_hour="0"+int_hour;
		if(int_minute<10)
		   int_minute="0"+int_minute;
		if(int_second<10)
		   int_second="0"+int_second;
		if(int_day>0)
			str_time=int_day+str_day;
		else
			str_time = "";
		if(int_hour>0)
			str_time+=int_hour+str_hour;
		if(int_minute>0)
			str_time+=int_minute+str_minute;
		if(int_second>0)
			str_time+=int_second+str_second;
		//str_time = int_day+"天"+int_hour+"小时"+int_minute+"分钟"+int_second+"秒";
		$(".time span").html(str_time);
		setTimeout("$.showTime()",1000);
	}else{
		//$(".time span").html("测试结束");
		//refresh
	}
}

// 返回顶部按钮
$(function(){
    $(window).scroll(function(){  //只要窗口滚动,就触发下面代码
        var scrollt = document.documentElement.scrollTop + document.body.scrollTop; //获取滚动后的高度
        if( scrollt >200 ){  //判断滚动后高度超过200px,就显示
            $("#gotop").fadeIn(400); //淡出
        }else{
            $("#gotop").stop().fadeOut(400); //如果返回或者没有超过,就淡入.必须加上stop()停止之前动画,否则会出现闪动
        }
    });
    $("#gotop").click(function(){ //当点击标签的时候,使用animate在200毫秒的时间内,滚到顶部
        $("html,body").animate({scrollTop:"0px"},200);
    });
});