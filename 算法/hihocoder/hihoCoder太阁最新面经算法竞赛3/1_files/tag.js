+function ($) { "use strict";
	var tags = '.h-tags';
	var tags_selected = '.h-tags-selected';
	var tag = '.h-tag';
	var tag_cancel = '.h-tag-cancel';
	var tag_option = '.h-tag-option';
	var tag_cate = '.h-tags-cate-item';
	var tags_options_status = '.h-tags-options-status';
	
	function cancel() {
		var $this = $(this);
		var $tag = $this.prevAll(tag);
		var $parent = $this.parent();
		$parent.remove();
	}
	
	function select(e) {
		var $this = $(this);
		e.preventDefault();
		var $tags_selected = $this.parent().parent().parent().prevAll(tags_selected);
		var $existed_tag = $tags_selected.find('[data-tid=' + $this.data('tid') + ']');
		if($existed_tag.length == 0) {
			$tags_selected.append('<li><a class="h-tag q-tag" href="/discuss/tag/' + $this.html() + '" data-tid="' 
				+ $this.data('tid') 
				+ '">' + $this.html() + '</a><a class="h-tag-cancel btn">x</a><input class="hide" name="tag-list[]" value="' 
				+ $this.data('tid') + '" /></li>');
		}
	}
	
	function toggleTagCate(){
		var $this = $(this);
		var tag_list = $('.h-tags-list');
		var index = $this.data('index');
		
		tag_list.hide();
		$this.siblings().removeClass('active');
		tag_list.eq(index).show();
		$this.addClass('active');
	}
	
	function toggleTagsOptions(){
		$('.h-tags-options').toggle();
	}
	
	$(document)
    	.on('click.hiho.tag', tag_cancel, cancel)
		.on('click.hiho.tag', tag_option, select)
		.on('click.hiho.tag', tag_cate, toggleTagCate)
		.on('click.hiho.tag', tags_options_status, toggleTagsOptions);
}(jQuery);
