(function ($){
	var editor = ace.edit('code-editor');
	var editor_full = ace.edit('fullscreen-code-editor');
	var keyboard ='.tl-code-editor-toolbar .h-toggle-keyboard';
	var lang = '.tl-code-editor-toolbar .h-select-lang';
	var custom_test_case = '.custom-test-case input';
	var fullscreenWrap = '#fullscreen-code-editor-wrap';
	var fullscreen = '.tl-code-editor-toolbar .h-fullscreen';
	var resize_screen = '.tl-code-editor-toolbar .h-resize-screen';
	var separator = '#fullscreen-code-editor-wrap .separator';
	var keyboard_set = {
			'emacs'   :'ace/keyboard/emacs',
			'normal'  :'',
			'vim'     :'ace/keyboard/vim'
	};
	var mode = {
			'GCC'  :'ace/mode/c_cpp',
			'G++'  :'ace/mode/c_cpp',
			'C#'   :'ace/mode/csharp',
			'Java' :'ace/mode/java',
			'Python2': 'ace/mode/python',
			'Python3': 'ace/mode/python',
	};
	
	
	function init(){
		window.aceEditor = editor;
		editor.setTheme('ace/theme/tomorrow_night_eighties');
		editor.getSession().setMode('ace/mode/c_cpp');
		window.aceFullEditor = editor_full;
		editor_full.setTheme('ace/theme/tomorrow_night_eighties');
		editor_full.getSession().setMode('ace/mode/c_cpp');
	}
	
	function setKeyboard(e){
		var $this = $(this);
		var kb = $this.data('keyboard');
		
		editor.setKeyboardHandler(keyboard_set[kb]);
		editor_full.setKeyboardHandler(keyboard_set[kb]);
		
		//sync full-screen and resize
		$(keyboard).each(function(){
			if($(this).is('.'+kb))
				$(this).addClass('active');
			else
				$(this).removeClass('active');
		});
	}
	
	function setMode(e){
		var $this = $(this);
		editor.getSession().setMode(mode[$this.val()]);
		editor_full.getSession().setMode(mode[$this.val()]);
		
		//sync full-screen and resize
		$(lang).each(function(){
			var sindex = $this.prop('selectedIndex');
			$(this).prop('selectedIndex',sindex);
		});
	}
	
	function toggleCustomTextarea(e){
		var $this = $(this);
		var ta = $('.h-custom-case-textarea');
		
		if($this.prop('checked')){
			ta.removeClass('hide').focus();
			$(custom_test_case).each(function(){
				$(this).prop('checked',true);
			});
		}else{
			ta.addClass('hide');
			$(custom_test_case).each(function(){
				$(this).prop('checked',false);
			});
		}
	}
	
	function toggleScreen(e){
		var full_dom = $(fullscreenWrap);
		e.preventDefault();
		
		if(e.data.type == 'full'){
			
			$('body').css('overflow-y','hidden');
			full_dom.removeClass('hide');
			syncResizeToFull();
		}
		else if(e.data.type == 'resize'){
			$('body').css('overflow-y','visible');
			full_dom.addClass('hide');
			syncFullToResize();
		}
	}
	
	function syncResizeToFull(){
		var et_cnt = editor.getValue();
		
		//editor
		//editor_full.setValue(et_cnt);
		editor_full.resize(true);
		//custom test case
		var cs = $('#h-custom-case').val();
		$('#h-custom-case-fullscreen').val(cs);
	}
	
	function syncFullToResize(){
		var et_cnt_full = editor_full.getValue();
		
		//editor
		//editor.setValue(et_cnt_full);
		editor.resize(true);
		//custom test case
		var cs_fs = $('#h-custom-case-fullscreen').val();
		$('#h-custom-case').val(cs_fs);
	}
	
	function dragSeparator(ev){
		var left_bar = $('#fullscreen-code-editor-wrap .left-bar');
		var right_bar = $('#fullscreen-code-editor-wrap .right-bar');
		var dom_width = $(fullscreenWrap).width();
		var star_x = ev.pageX;
		
		var left_bar_perc =  (left_bar.width()+19) / dom_width * 100 ;// padding
		var right_bar_perc = (right_bar.width()) / dom_width * 100;
		
		$(fullscreenWrap).mousemove(function(e){
			var end_x = e.pageX;
			var move_distance = end_x - star_x;
			var move_perc = Math.abs(move_distance) / dom_width * 100;
			
			if(move_distance < 0){
				var left_width = (left_bar_perc - move_perc) + '%';
				var right_width = (right_bar_perc + move_perc) + '%';
				
				left_bar.css('width',left_width);
				right_bar.css('width',right_width);
			}
			else{
				var left_width = (left_bar_perc + move_perc) + '%' ;
				var right_width = (right_bar_perc - move_perc) + '%';
				
				left_bar.css('width',left_width);
 				right_bar.css('width',right_width);
			}
		});

		$('body').mouseup(function(e){
			$(fullscreenWrap).unbind('mousemove');
		});
	}
	
	
	// init 
	//=============================
	
	init();
	
	$(document)
		.on('click.hiho.code-editor', keyboard, setKeyboard)
		.on('change.hiho.code-editor', lang, setMode)
		.on('click.hido.code-editor', custom_test_case, toggleCustomTextarea)
		.on('click.hido.code-editor', fullscreen, {type:'full'}, toggleScreen)
		.on('click.hido.code-editor', resize_screen, {type:'resize'}, toggleScreen)
		.on('mousedown.hido.code-editor',separator, dragSeparator);
	
})(jQuery);