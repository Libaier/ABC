var api = {
	path:'/api/',
	logout:function(callback){
		$.post(this.path+'user/logout.json', {}, callback || Callbacks.redirect('url'), 'json');	
	},
	
	googleLogin:function(callback){
		$.post(this.path+'SNS/googleLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	githubLogin:function(callback){
		$.post(this.path+'SNS/githubLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	sinaWeiBoLogin:function(callback){
		$.post(this.path+'SNS/SinaWeiboLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	renrenLogin:function(callback){
		$.post(this.path+'SNS/RenrenLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	QQLogin:function(callback){
		$.post(this.path+'SNS/QQLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	liveLogin:function(callback){
		$.post(this.path+'SNS/LiveLogin.json', {}, callback || Callbacks.redirect('url'), 'json');
	},
	
	bindAcct:function(bind_secure, accept, newacct, name, successCallback, errorCallback) {
		$.post(this.path+'user/bindAcct.json', {'bind-secure':bind_secure, 'accept':accept, 'newacct':newacct, 'name':name}, $.checkResponse(successCallback, errorCallback), 'json')
	},
	
	autoFileSize:function(filesize){
    	if(filesize>=1024*1024*1024) //是否超过1G
    		return Math.round(filesize*100/1024/1024/1024)/100+'GB';
    	if(filesize>=1024*1024) //是否超过1M
    		return Math.round(filesize*10/1024/1024)/10+'MB'; 
    	if(filesize>=1024) //是否超过1K
    		return Math.round(filesize/1024)+'KB'; 
    	return filesize+'Byte'; //默认为字节数 
    },
    
    oppositeChecked:function(){
		ele = $("#fileupload input[type='checkbox']");
		for(var i=0;i<ele.length;i++){
			ele[i].checked = ele[i].checked?false:true;
		}
	},
	
	unsubscribe:function(u, v, callback) {
		$.post(this.path+'user/unsubscribe.json', {'u':u, 'v':v}, $.checkResponse(callback), 'json');
	}
}