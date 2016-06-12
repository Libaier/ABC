+function ($) { "use strict";
	var apiQOps = '/api/discuss/questionOps.json';
	var apiAOps = '/api/discuss/answerOps.json';
	var apiTOps = '/api/discuss/tagOps.json';
	var apiFOps = '/api/discuss/friendOps.json';
	var apiCOps = '/api/discuss/commentOps.json';
	var qbmon = '.h-q-bmon';
	var qbmoff = '.h-q-bmoff';
	var qvote = '.h-q-vote';
	var avote = '.h-a-vote';
	var aaccept = '.h-a-accept';
	var dmb = '.h-d-bookmark';
	var tfollow = '.h-t-follow';
	var ffollow = '.h-f-follow';
	var c_showac = '.h-show-add-comment a';
	var c_reply = '.h-reply-comment';
	var c_reply_cancel = '.h-reply-cancel';
	var c_edit = '.h-comment-edit';
	var c_edit_cancel = '.h-com-edit-cancel';
	var c_edit_submit = '.h-com-edit-submit';
	
	//bookmark on
	function bookmarkonCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $parent = $this.parent();
				$parent.removeClass('bookmark-on').addClass('bookmark-off');
				$this.removeClass('h-q-bmon').addClass('h-q-bmoff').removeClass('icon-star-empty').addClass('icon-star');
				$this.data('op', 'bmoff');
				var $bmcount = $parent.next('.h-q-bmcount');
				var count = parseInt($bmcount.html()) + 1;
				$bmcount.html(count);
			}
		}
	}
	
	function bookmarkon() {
		var $this = $(this);
		var qid = $this.data('qid');
		var op = $this.data('op');
		$.post(apiQOps, {'qid':qid, 'op':op}, $.checkResponse(bookmarkonCallback($this)), 'json');
	}
	//bookmark off
	function bookmarkoffCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $parent = $this.parent();
				$parent.removeClass('bookmark-off').addClass('bookmark-on');
				$this.removeClass('h-q-bmoff').addClass('h-q-bmon').removeClass('icon-star').addClass('icon-star-empty');
				$this.data('op', 'bmon');
				var $bmcount = $parent.next('.h-q-bmcount');
				var count = parseInt($bmcount.html()) - 1;
				$bmcount.html(count);
			}
		}
	}
	
	function bookmarkoff() {
		var $this = $(this);
		var qid = $this.data('qid');
		var op = $this.data('op');
		$.post(apiQOps, {'qid':qid, 'op':op}, $.checkResponse(bookmarkoffCallback($this)), 'json');
	}
	//question vote
	function qvoteCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $vote = $this.parent().parent();
				var $voteup = $vote.children('.vote-up-on');
				$voteup.removeClass('vote-up-on').addClass('vote-up-off');
				$voteup.children('.h-q-vote').removeClass('h-q-vote');
				var $votedown = $vote.children('.vote-down-on');
				$votedown.removeClass('vote-down-on').addClass('vote-down-off');
				$votedown.children('.h-q-vote').removeClass('h-q-vote');
				var $votecount = $vote.children('.h-q-votecount');
				var count = parseInt($votecount.html());
				if($this.data('op') == 'voteup') {
					count = count + 1;
					$votecount.html(count);
				}
				//no displat against
			}
		}
	}
	function questionvote() {
		var $this = $(this);
		var qid = $this.data('qid');
		var op = $this.data('op');
		$.post(apiQOps, {'qid':qid, 'op':op}, qvoteCallback($this), 'json');
	}
	
	//answer vote
	function avoteCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $vote = $this.parent().parent();
				var $voteup = $vote.children('.vote-up-on');
				$voteup.removeClass('vote-up-on').addClass('vote-up-off');
				$voteup.children('.h-a-vote').removeClass('h-a-vote');
				var $votedown = $vote.children('.vote-down-on');
				$votedown.removeClass('vote-down-on').addClass('vote-down-off');
				$votedown.children('.h-a-vote').removeClass('h-a-vote');
				var $votecount = $vote.children('.h-a-votecount');
				var count = parseInt($votecount.html());
				if($this.data('op') == 'voteup') {
					count = count + 1;
					$votecount.html(count);
				}
				//no displat against
			}
		}
	}
	function answervote() {
		var $this = $(this);
		var aid = $this.data('aid');
		var op = $this.data('op');
		$.post(apiAOps, {'aid':aid, 'op':op}, avoteCallback($this), 'json');
	}
	//answer accept
	function aacceptCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $sibling = $this.siblings(aaccept);
				$this.addClass('hide');
				$sibling.removeClass('hide');
				var $accepticon = $this.closest('.h-answer').find('.h-a-acceptedicon');
				if($this.data('op') == 'accept')
					$accepticon.removeClass('hide');
				else
					$accepticon.addClass('hide');
			}
		}
	}
	function answeraccept() {
		var $this = $(this);
		var aid = $this.data('aid');
		var op = $this.data('op');
		$.post(apiAOps, {'aid':aid, 'op':op}, aacceptCallback($this), 'json');
	}
	//dicuss:bookmarked questions bookmark on/off handler
	function dbookmarkCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $sibling = $this.siblings(dmb);
				$this.addClass('hide');
				$sibling.removeClass('hide');
			}
		}
	}
	function dbookmark() {
		var $this = $(this);
		var qid = $this.data('qid');
		var op = $this.data('op');
		$.post(apiQOps, {'qid':qid, 'op':op}, $.checkResponse(dbookmarkCallback($this)), 'json');
	}
	//tag follow
	function tagfollowCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $sibling = $this.siblings(tfollow);
				$this.addClass('hide');
				$sibling.removeClass('hide');
				var $followcount = $this.siblings().children('.h-t-followcount');
				var count = parseInt($followcount.html());
				if($this.data('op') == 'follow')
					count = count + 1;
				else
					count = count - 1;
				$followcount.html(count);
			}
		}
	}
	function tagfollow() {
		var $this = $(this);
		var tid = $this.data('tid');
		var op = $this.data('op');
		$.post(apiTOps, {'tid':tid, 'op':op}, $.checkResponse(tagfollowCallback($this)), 'json');
	}
	
	//friend follow
	function friendfollowCallback($this) {
		return function(rsp, result, xhr) {
			if(rsp.response['message'] == 'success') {
				var $sibling = $this.siblings(ffollow);
				$this.addClass('hide');
				$sibling.removeClass('hide');
			}
		}
	}
	function friendfollow() {
		var $this = $(this);
		var fid = $this.data('fid');
		var op = $this.data('op');
		$.post(apiFOps, {'fid':fid, 'op':op}, $.checkResponse(friendfollowCallback($this)), 'json');
	}
		
	function commentShowAddForm(e){
		var $this = $(this);
		e.preventDefault();
		$this.parent().hide();
		$this.parent().siblings('.add-comment').removeClass('hide');
	}
	
	function commentReply(e){
		var $this = $(this);
		e.preventDefault();
		var comment = $this.closest('.comment-list');
		var author = $this.parent().siblings('.author-name').children('a');
		var replyTo = comment.find('.h-reply-to .user');
		
		comment.find('.h-reply-to').removeClass('hide');
		comment.children('.h-show-add-comment').hide();
		comment.children('.add-comment').removeClass('hide');
		comment.children('.add-comment').find('textarea').focus();
		replyTo.text(author.text());
		replyTo.attr('href',author.attr('href'));
		replyTo.siblings('input').val(author.data('uid'));
	}
	
	function commentReplyCancel(e){
		var $this = $(this);
		e.preventDefault();
		
		$this.parent().addClass('hide');
		$this.siblings('input').val(0);
	}
	
	function commentEdit(e){
		var editform = '<div class="h-com-edit-form" style="margin-top:5px;">'
			+ '<textarea class="form-control edit-content" rows="1"></textarea>'
			+ '<div class="clearfix edit-action" style="margin-top:5px;">' 
			+ '<button type="submit" class="btn btn-primary pull-right h-com-edit-submit" style="padding: 4px 10px;">修改评论</button>'
			+ '<button class="btn btn-default pull-right h-com-edit-cancel" style="padding: 4px 10px;margin-right:10px;">取消</button></div>';
		var $this = $(this);
		var main = $this.closest('.comment-main');
		var post = main.children('.comment-post');
		e.preventDefault();
		
		post.hide();
		main.find('.comment-action').hide();
		main.append(editform);
		main.children('.h-com-edit-form').find('textarea').focus().text(post.text());
	}
	
	function commentEditCancel(e){
		var $this = $(this);
		var edit = $this.closest('.h-com-edit-form');
		//e.preventDefault();
		
		edit.siblings('.comment-post').show();
		edit.siblings('.comment-info').children('.comment-action').show();
		edit.remove();
	}
	
	//comment edit submit
	function commentEditSubmitCallback($this){
		return function(rsp, result, xhr){
			if(rsp.response['message'] == 'success') {
				var edit = $this.parent().parent();
				var content = edit.children('textarea').val();
				edit.siblings('.comment-post').show().text(content);
				edit.siblings('.comment-info').children('.comment-action').show();
				edit.remove();
			}
		}
	}
	
	function commentEditSubmit(e){
		var $this = $(this);
		var edit = $this.parent().parent();
		var content = edit.children('textarea').val();
		var cmid = edit.siblings('.comment-post').data('cmid');
		e.preventDefault();
		
		$.post(apiCOps, {'comment-id':cmid, 'content':content, 'ops-type':'edit'}, $.checkResponse(commentEditSubmitCallback($this)), 'json');
	}
	
	//comment delete
	function commentDeleteCallback($this){
		return function(rsp, result, xhr){
			if(rsp.response['message'] == 'success') {
				var cm_item = $this.closest('.comment-item');
				cm_item.remove();
			}
		}
	}
	
	$.fn.commentDelete = function(){
		var $this = $(this);
		var cm_info = $this.parent().parent();
		var cmid = cm_info.siblings('.comment-post').data('cmid');
		
		$.post(apiCOps, {'comment-id':cmid, 'ops-type':'delete'}, $.checkResponse(commentDeleteCallback($this)), 'json');
	}
	
	
	$(document)
    	.on('click.hiho.question', qbmon, bookmarkon)
    	.on('click.hiho.question', qbmoff, bookmarkoff)
    	.on('click.hiho.question', qvote, questionvote)
    	.on('click.hiho.question', avote, answervote)
    	.on('click.hiho.question', aaccept, answeraccept)
    	.on('click.hiho.discuss', dmb, dbookmark)
    	.on('click.hiho.tag', tfollow, tagfollow)
		.on('click.hiho.user', ffollow, friendfollow)
		.on('click.hiho.comment', c_showac, commentShowAddForm)
		.on('click.hiho.comment', c_reply, commentReply)
		.on('click.hiho.comment', c_reply_cancel, commentReplyCancel)
		.on('click.hiho.comment', c_edit, commentEdit)
		.on('click.hiho.comment', c_edit_cancel, commentEditCancel)
		.on('click.hiho.comment', c_edit_submit, commentEditSubmit);
}(jQuery);