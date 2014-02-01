/**
 * @file
 * A JavaScript file for the theme.
 */
/*
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) { */

jQuery.noConflict();
(function( $ ) {
$(function() {
$(document).ready(function() {
    

	// EXTERNAL LINKS
	//---------------------------
	$('a[rel*=external]').click(function(){
		window.open($(this).attr('href'));
		return false; 
	});
		
		
	// FITVIDS
	//---------------------------
	$('.fitvids').fitVids();
	
	
	// TOGGLES
	//---------------------------
	$('#menu-toggle a').click( function(){
		switch($(this).attr('class')){
			case 'open-nav':
				$(this).attr('class','close-nav');
				$('body').addClass('menu-open');
				$('#filter-toggle span.cover').addClass('fade');
				$('#nav').height('auto');
				resizeNav();
				if($('#page').height() <= $('#nav').height()){
					$('#page').height($('#nav').height());
				}
			break;
			case 'close-nav':
				$(this).attr('class','open-nav');
				$('body').removeClass('menu-open');
				$('#filter-toggle span.cover').removeClass('fade');
				$('#page').height('auto');
			break;
		}
		return false;
	});

	$('#filter-toggle a').click( function(){
		switch($(this).attr('class')){
			case 'open-filter':
				$(this).attr('class','close-filter');
				$('body').addClass('filter-open');
				$('#menu-toggle span').addClass('fade');
				$('#filter').height('auto');
				resizeNav();
				if($('#page').height() <= $('#filter').height()){
					$('#page').height($('#filter').height());
				}
			break;
			case 'close-filter':
				$(this).attr('class','open-filter');
				$('body').removeClass('filter-open');
				$('#menu-toggle span').removeClass('fade');
				$('#page').height('');
			break;
		}
		return false;
	});
	
	// Add floating toggle once scrolled passed toggles
	$(window).scroll(function(){
		var top = $(this).scrollTop();
		if(top > 135){
			$('body').addClass('floating-toggle');  
		}else{
			$('body').removeClass('floating-toggle');  
		}
	});
	$('#floating-filter-toggle').click( function(){
		$("html, body").animate({ scrollTop: 0 });
		$('#filter-toggle a').click();
	})
	
	// Resize nav to page height
	function resizeNav(){
		if($('#nav').height() < $('#page').height()){
			$('#nav').height($('#page').height());
		}
		if($('#filter').height() < $('#page').height()){
			$('#filter').height($('#page').height());
		} 
	}
	resizeNav();
	$(window).resize(function() {
		resizeNav();
	})
	
	
	// PRESS THUMBS SQUARE
	//---------------------------
	squareBox = function(){
		// Match height to width so css height:100% works as intended
		$('.view-news.view-display-id-press .thumb .inner').each( function(){
			var width = $(this).width();
			$(this).height(width);
		});
	}
	if($('body').hasClass('page-press-coverage')){
		squareBox();
		$(window).resize(function() {
			squareBox();
		})
	}
	
	
	// FRONT
	//---------------------------
	if($('body').hasClass('page-node-60')){
		
		winW = $(window).width();
		winH = $(window).height();
		if(winW < 740){
			if($('.view-news').length > 0){
				marg = $(window).height() - $('#logo-home').height() - $('.info-box h2').height() - 90;
				$('#home').css('top',marg).css('margin-bottom',marg);
			} else{
				$('#home').css('top',$(window).height() - $('#logo-home').height() - 40);
			}	
		}
		if($('#nav').height() < winH){
			$('#nav').css('height',winH+'px !important');
		}else{
			$('#nav').css('height','100% !important');
		}
		
		function resizeOverlay(){
			$('#overlay').width($(window).width()-190);
		}
		resizeOverlay();
		$(window).resize( function(){
			resizeOverlay();
		})
		
	}
	
	
	// EXHIBITIONS
	//---------------------------
	if($('body').hasClass('page-node-21')){
		if($('.region-content-above').length > 0){
			$('#block-views-page-image-block').hide();
		}
	}
	
	
	// ARTWORK NODE PAGE
	//---------------------------
	
	// window resize function for artwork image
	function artworkResize(offsetY){
		winH = $(window).height();
		winW = $(window).width();
		// Set height of pager arrows to window height
		$('#artwork .artwork-pager').height(winH-$('#artwork-info-bar').height()-50);
		$('#artwork-image').waitForImages( function(){
			// Set divs to height of page and align info bar to bottom
			$('#artwork-image, #artwork-image div').height(winH-offsetY);
			if(winW <= 600 && winW > 480){
				$('#artwork-image, #artwork-image div').height(winH-offsetY+80);
			}
			if(winW <= 480 && $('body').hasClass('page-node-33')){
				$('#artwork-image, #artwork-image div').height(winH-offsetY+47);
			}
			if(winW <= 480 && $('body').hasClass('node-type-artwork')){
				$('#artwork-image, #artwork-image div').height(winH-offsetY+57);
			}
			if(winW <= 480 && $('body').hasClass('page-images')){
				$('#artwork-image, #artwork-image div').height(winH-offsetY+47);
			}
			// Set page height to popup height
			$('#page').height($('#artwork').height()-10);
		});
	}
	
	// add click event to read more link
	$('.node-artwork #read-about').click( function(){
		$("html, body").animate({ scrollTop: $('#artwork-info-bar').offset().top + 7 });
		return false
	});
	
	if($('body').hasClass('node-type-artwork')){
		// setup artwork resize function
		artworkResize(230);
		$(window).resize( function(){
			artworkResize(230);
		})
	}
	
	
	// PORTFOLIO LIGHTBOX POPUP
	//---------------------------
	
	// Close artwork lightbox
	$('#artwork .close').click( function(){
		$('body').removeClass('popup');
		$('#artwork').removeClass('active').addClass('notloaded');
		$('#page-content').removeClass('fade');
		$('#artwork #load').html('');
		$('#page').height('auto');
		$(document).scrollTop(yPos);
		return false;
	});
	// Artwork lightbox prev/next pager
	$('.page-node-33 #artwork .artwork-pager').click( function(){
		var nid = $(this).attr('rel');
		var prev = $('#artwork-'+nid).parents('.views-row').prevAll(":visible:first");
		var next = $('#artwork-'+nid).parents('.views-row').nextAll(":visible:first");
		$('body').addClass('loading-artwork');
		$('#loading').css('top', ($(window).height()/2) - ($('#artwork-info-bar').height()/2) +'px' );
		switch($(this).attr('id')){
			case 'artwork-prev':
				// If no previous, show last
				if(prev.length === 0){
					$('.view-portfolio .views-row:visible').last().find('.artwork').click();
				}else{
					prev.find('.artwork').click();
				}
			break;
			case 'artwork-next':
			// If no next, show first
				if(next.length === 0){
					$('.view-portfolio .views-row:visible').first().find('.artwork').click();
				}else{
					next.find('.artwork').click();
				}
			break;
		}
		return false;
	});
	
	// .artwork click function
	function artworkPopup() {
		var obj = $(this);
		var path = obj.attr('href');
		yPos = $(document).scrollTop();
		$('body').addClass('loading').addClass('popup');
		if(!$('body').hasClass('loading-artwork')){
			$('#loading').css('top', (obj.offset().top) + (obj.height()/2) +'px').css('left',obj.offset().left + (obj.width()/2))+'px';
		}
		if($('#artwork').hasClass('notloaded')){
			$('#artwork').removeClass('notloaded');
		}else{
			$('#artwork').addClass('fade')
		}	
		$.ajax({
			type: 'GET',
			url: path,
			// pass ajax response type to load stripped down ajax template
			data: { response_type: 'ajax' },
			success: function(html) {
				$('#artwork').removeClass('fade').addClass('active');
				$('#artwork #load').html(html);
				$('#loading').css('top', ($(window).height()/2) - ($('#artwork-info-bar').height()/2) +'px' ).css('left','50%');
				$('#artwork-image, #artwork-image div').height($(window).height());
				$('#artwork-image img').hide();
				$('#artwork-image').waitForImages( function(){
					$('body').removeClass('loading').removeClass('loading-artwork');
					$('#artwork-image img').fadeIn();
				});
				$('#page-content').addClass('fade');
				artworkResize(155);
				$(document).scrollTop(0);
				
				// add click event to read more link
				$('#artwork #read-about').click( function(){
					$("html, body").animate({ scrollTop: $('#artwork-info-bar').offset().top + 7 });
					return false
				});
				
				// Set pagers rel to nid to setup prev/next links
				$('#artwork .artwork-pager').attr('rel',obj.data('nid'));
				
			}
		});
		return false;
	};
	$('.artwork').on('click', artworkPopup );
	
	
	// PORTFOLIO FILTER AJAX
	//---------------------------
	
	function filterPortfolio(obj, filter){
		
		// Check for class and filter content instead of loading
		if(obj.hasClass('filter')){		
			switch(filter){
				case 'disciplines':
					// Show/hide matching artworks
					medium = obj.data('medium');
					$('.artwork').each( function(){
						if($(this).data('medium') != medium){
							$(this).parents('.views-row').hide();
						} else{
							$(this).parents('.views-row').show();
						}
					});
					$('#disciplines a.active').removeClass('active');
					project = $('#projects .filter a.active').data('project');
					window.location.hash = '#/'+project+'/'+medium;
				break
				case 'projects':
					loadPortfolioInfo(obj);
					// Show/hide matching artworks
					project = obj.data('project');
					$('.artwork').each( function(){
						if($(this).data('project') != project){
							$(this).parents('.views-row').hide();
						} else{
							$(this).parents('.views-row').show();
						}
					});
					$('#projects a.active').removeClass('active');
					medium = $('#disciplines .filter a.active').data('medium');
					window.location.hash = '#/'+medium+'/'+project;
				break
			}
			obj.addClass('active');
				
		} else{

			var path = '/dev/'+obj.attr('href');
			$('#page-content').addClass('fade');
			$('body').addClass('loading');
			$('#loading').css('top',obj.offset().top+9+'px').css('left',obj.offset().left-13+'px');
			
			loadPortfolioInfo(obj);
			
			// Load artwork
			$.ajax({
				type: 'GET',
				url: path,
				// pass ajax response type to load stripped down ajax template
				data: { response_type: 'ajax' },
				success: function(html) {
					
					switch(filter){
						case 'disciplines':
							$('#projects .filter a').addClass('filter');
							$('#projects a.active').removeClass('active');
							$('#projects a.all').removeClass('reset').addClass('active');
							$('#disciplines .filter a').removeClass('filter, fade');
							$('#disciplines a.active').removeClass('active');
							$('#disciplines a.all').addClass('reset');
							closePortfolioInfo();
							
							// Create array from data attr, and disable irrevalent links
							var projects = obj.data('projects').split(' ');
							$('#projects .filter a').addClass('fade');
							for(var i=0; i<projects.length; i++) {
								$('#projects .filter a').each( function(){
									if($(this).data('project') == projects[i]){
										$(this).removeClass('fade');
									}
								});
							}
						break
						case 'projects':
							$('#disciplines .filter a').addClass('filter');
							$('#disciplines a.active').removeClass('active');
							$('#disciplines a.all').removeClass('reset').addClass('active');
							$('#projects .filter a').removeClass('filter, fade');
							$('#projects a.active').removeClass('active');
							$('#projects a.all').addClass('reset');
							
							// Create array from data attr, and disable irrevalent links
							var mediums = obj.data('mediums').split(' ');
							$('#disciplines .filter a').addClass('fade');
							for(var i=0; i<mediums.length; i++) {
								$('#disciplines .filter a').each( function(){
									if($(this).data('medium') == mediums[i]){
										$(this).removeClass('fade');
									}
								});
							}
						break
					}
					
					$('#page-content').removeClass('fade');
					$('body').removeClass('loading');
					obj.addClass('active');
					$('#page, #nav, #filter').height('auto');
					resizeNav();
					$('#node-content').html(html);
					$("html, body").animate({ scrollTop: 0 });
					$('.artwork').on('click', artworkPopup );
					
					// If hash exists and there is a second element, click to filter the results
					if(hashExists == 1){
						hash = window.location.hash.substring(1).split('/');
						if(hash[2]){
							$('.filter a.'+hash[2]).click();
						}
						// Reset hash exists so path rewrite functions properly next time
						hashExists = 0;
					}else{
						url = path.split('/');
						window.location.hash = '#/'+url[2];
					}
						
				}
			});
			
		}		
		
	}
	
	// When clicking on 'All' reset links
	function resetPortfolio(obj, filter){
		// Check class and load new content based on active link
		if(obj.hasClass('reset')){
			switch(filter){
				case 'disciplines':
					$('#projects .filter a').removeClass('filter');
					$('#projects a.active').click();
				break;
				case 'projects':
					$('#disciplines .filter a').removeClass('filter');
					$('#disciplines a.active').click();
				break;
			}
		}
		// Or displayed all hidden/filtered artworks
		else{
			$('.artwork').parents('.views-row').show();
		}
		switch(filter){
			case 'disciplines':
				$('#disciplines a.active').removeClass('active');
				project = $('#projects .filter a.active').data('project');
				window.location.hash = '#/'+project;
			break;
			case 'projects':
				$('#projects a.active').removeClass('active');
				medium = $('#disciplines .filter a.active').data('medium');
				window.location.hash = '#/'+medium;
			break;
		}
		obj.addClass('active');
	}
	
	// Ajax load portfolio info block
	function loadPortfolioInfo(obj){
		// get project from path
		termUrl = obj.attr('href').split('/');
		projectName = obj.text();
		// Reset project info divs to closed state
		$('#project-info').removeClass('opened');
		if($('#project-info-description').is(':visible')){
			$('#project-info-description').slideUp();
		}
		$('#project-info #project-info-toggle a').attr('class','open');
				 
		$.ajax({
			type: 'GET',
			url: '/dev/project/'+termUrl[2],
			// pass ajax response type to load stripped down ajax template
			data: { response_type: 'ajax' },
			success: function(html) {
				$('body').addClass('project-info');
				$('#project-info h2').html(projectName);
				$('#project-info .project-title').html(projectName);
				$('#project-info-description .load').html($(html).find('.taxonomy-term-description'));
			}
		})
	}
	
	// Close/hide portfolio info block
	function closePortfolioInfo(){
		$('#project-info').removeClass('opened');
		$('#project-info-description').slideUp();
		$('#project-info #project-info-toggle a').attr('class','open');
		$('body').removeClass('project-info');
	}
	
	// Show/hide project info
	$('#project-info-toggle a').click( function(){
		if($(this).attr('class') == 'open'){
			$(this).attr('class','close');
			$('#project-info').addClass('opened');
		} else{
			$(this).attr('class','open');
			$('#project-info').removeClass('opened');
		}
		$('#project-info-description').slideToggle('fast');
		return false;
	});
		
	$('#disciplines .filter a').click( function (){ 
		// Dont add click function if link is disabled
		if(!$(this).hasClass('fade')){
			filterPortfolio($(this), 'disciplines');
		}
		return false;
	});
	$('#projects .filter a').click( function (){ 
		// Dont add click function if link is disabled
		if(!$(this).hasClass('fade')){
			filterPortfolio($(this), 'projects');
			return false;
		}
	});
	$('#disciplines a.all').click( function (){ 
		// Reload page if both resets are active
		if($(this).hasClass('reset') && $('#projects a.all').hasClass('active')){
		}
		// Or run function to reload content
		else{
			resetPortfolio($(this), 'disciplines');
			return false;
		}
	});
	$('#projects a.all').click( function (){ 
		// Reload page if both resets are active
		if($(this).hasClass('reset') && $('#disciplines a.all').hasClass('active')){
		}
		// Or run function to reload content
		else{
			resetPortfolio($(this), 'projects');
			closePortfolioInfo();
			return false;
		}
	});
	
	if($('body').hasClass('page-node-33')){
		// Check for url hash and load content
		hashExists = 0;
		if(window.location.hash && window.location.hash != ''){
			hashExists = 1;
			hash = window.location.hash.substring(1).split('/');
			$('.filter a.'+hash[1]).click();
		}
		// setup artwork resize function
		$(window).resize( function(){
			artworkResize(155)
		})
	}
	
	
	// IMAGES LIGHTBOX POPUP
	//---------------------------
	
	// Images lightbox prev/next pager
	$('.page-images #artwork .artwork-pager').click( function(){
		var nid = $(this).attr('rel');
		var prev = $('#'+nid).parents('.views-row').prev();
		var next = $('#'+nid).parents('.views-row').next();
		$('body').addClass('loading-artwork');
		$('#loading').css('top', ($(window).height()/2) - ($('#artwork-info-bar').height()/2) +'px' );
		switch($(this).attr('id')){
			case 'artwork-prev':
				// If no previous, show last
				if(prev.length === 0){
					$('.view-images .views-row-last').find('.image').click();
				}else{
					prev.find('.image').click();
				}
			break;
			case 'artwork-next':
			// If no next, show first
				if(next.length === 0){
					$('.view-images .views-row-first').find('.image').click();
				}else{
					next.find('.image').click();
				}
			break;
		}
		return false;
	});
	
	// .image click function
	function imagesPopup() {
		var obj = $(this);
		var path = obj.attr('href');
		yPos = $(document).scrollTop();
		$('body').addClass('loading').addClass('popup');
		$('#artwork').removeClass('notloaded').addClass('active');
		$('#artwork #load').html('<div id="artwork-image"><img src="'+path+'" /></div>');
		$('#artwork #load').append('<div id="artwork-info-bar" class="info-bar"><div class="inner clearfix"><span class="arrow">'+obj.attr('title')+'</span></div></div>');
		$('#loading').css('top', ($(window).height()/2) - ($('#artwork-info-bar').height()/2) +'px' ).css('left','50%');
		$('#artwork-image, #artwork-image div').height($(window).height());
		$('#artwork-image img').hide();
		$('#artwork-image').waitForImages( function(){
			$('body').removeClass('loading').removeClass('loading-artwork');
			$('#artwork-image img').fadeIn();
		});
		$('#page-content').addClass('fade');
		artworkResize(165);
		$(document).scrollTop(0);	
		// Set pagers rel to nid to setup prev/next links
		$('#artwork .artwork-pager').attr('rel',obj.data('nid'));
		return false;
	};
	$('.image').on('click', imagesPopup );
	
	
	// IMAGES FILTER AJAX
	//---------------------------
	$('.view-images.view-display-id-filter .view-content a').click( function(){
		
		var obj = $(this);
		var path = '/dev/'+obj.attr('href');
		$('#page-content').addClass('fade');
		$('body').addClass('loading');
		$('#loading').css('top',obj.offset().top+9+'px').css('left',obj.offset().left-15+'px');
		
		$.ajax({
            type: 'GET',
            url: path,
            data: { response_type: 'ajax' },
            success: function(html) {
				
				$('body').removeClass('loading');
				$('#page-content').removeClass('fade');
				$('#filter a.active').removeClass('active');
				obj.addClass('active');
				
				$('#node-content').html(html);
				hash = path.split("/"); 
				window.location.hash = '#/'+hash[1];
				$('.image').on('click', imagesPopup );
				
			}
        });
		
		return false;
	});
	
	// Check for url hash and load content
	if($('body').hasClass('page-images')){
		if(window.location.hash && window.location.hash != ''){
			hash = window.location.hash.substring(2);
			$('a.'+hash).click();
		}
		
		// setup artwork resize function
		$(window).resize( function(){
			artworkResize(155)
		})
	}



});
});
})(jQuery);
	
/*
  }
};


})(jQuery, Drupal, this, this.document); */
