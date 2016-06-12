+function ($) { "use strict";
	var apiConReg = '/api/contest/register.json';
	var conreg = '.h-c-reg';
	
	function contestregister() {
		var $this = $(this);
		var cid = $this.data('cid');
		$.post(apiConReg, {'cid':cid}, $.checkResponse(Callbacks.successRedirect('url')), 'json');
	}
	
	$(document)
		.on('click.hiho.contest', conreg, contestregister);
}(jQuery);