<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */

 // node IDs to display filter div on
 $filterIDS = array(31, 32, 33);
?>
<?php if(isset($node) && in_array($node->nid, $filterIDS)): ?>
<div id="artwork" class="transition notloaded">
    <div class="inner">
    <a class="close">Close</a>
    <a id="artwork-prev" class="artwork-pager">Previous</a>
    <a id="artwork-next" class="artwork-pager">Next</a>
    	<div id="load"></div>
    </div>
</div>
<?php endif; ?>

<div id="page">

  <header class="header transition width" id="header" role="banner">
	<?php if ($logo): ?>
		<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
	<?php endif; ?>
  </header>
  
  <div id="loading"></div>
  
  <div id="toggles" class="transition width">
  	<div id="menu-toggle" class="toggle transition"><a class="open-nav" href="#">Menu</a><span class="cover"></span></div>
    <?php if(isset($node) && in_array($node->nid, $filterIDS)):?>
	<div id="filter-toggle" class="toggle transition">
        <a class="open-filter" href="#">Filter 
		<span class="type">
		<?php 
			switch($node->nid){
				case 31:
				case 32:
					print 'Images';
				break;
				case 33:
					print 'Portfolio';
				break;
			}
		?>
        </span>
		</a>
        <span class="cover"></span>
	</div>
	<?php endif; ?>
  </div>
  <?php if(isset($node) && in_array($node->nid, $filterIDS)):?>
  <div id="floating-filter-toggle" class="transition"></div>
  <?php endif; ?>

  <div id="nav" class="transition menu">
  <div class="inner">
	<?php print render($page['navigation']); ?>
    <div id="social">
    	<div class="title">Let's keep it social</div>
        <ul>
            <li><a class="social_twitter" title="Twitter" href="https://twitter.com/luap_nosnibor" rel="external">Twitter</a></li>
            <li><a class="social_tumblr" title="Tumblr" href="http://luapnosnibor.tumblr.com/" rel="external">Tumblr</a></li>
            <li><a class="social_facebook" title="Facebook" href="https://www.facebook.com/luapstudio" rel="external">Facebook</a></li>
            <li><a class="social_instagram" title="Instagram" href="http://instagram.com/luapnosnibor" rel="external">Instagram</a></li>
        </ul>
    </div>
  </div>
  </div>
  
  <?php if(isset($node) && in_array($node->nid, $filterIDS)): ?>
	<div id="filter" class="transition menu">
	<?php
		if($node->nid == 31 || $node->nid == 32){
			$block = module_invoke('views', 'block_view', 'images-filter');
			print render($block);
		}
		if($node->nid == 33){
			include_once DRUPAL_ROOT . '/' . path_to_theme() . '/templates/include--portfolio-filter.inc';
		}
	?>
	</div>
  <?php endif; ?>
  
  <div id="main" class="transition width">

    <div id="content" class="transition" role="main">
    <div class="inner clearfix">
    
      <?php print render($tabs); ?>
	  <?php print $messages; ?>
      
      <a id="main-content"></a>
      
      <?php if($is_front):?>
        <div id="home">
            <div id="logo-home"><img src="<?php print path_to_theme(); ?>/images/logo_home.png" /></div>
            <?php
            $block = module_invoke('views', 'block_view', 'news-home');
            print render($block);
        ?>
        </div>
      <?php endif; ?>
	  
      <?php if ( 
	  			(isset($node) && $node->type == 'page' && $node->field_display_title['und'][0]['value'] == 1) ||
				(isset($node) && $node->type =='news_press')
				): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
	  
	  <?php print render($page['content_above']); ?>
      
      <?php $sidebar_first  = render($page['sidebar_first']); ?>
	  <?php if ($sidebar_first): ?>
		<aside class="sidebar" id="sidebar">
        <div class="inner">
        
        	<?php print $sidebar_first; ?>
            
            <?php if($node->type == 'news_press'): 
				$project = taxonomy_term_load($node->field_artwork_reference['und'][0]['node']->field_project['und'][0]['tid']);
				$medium = taxonomy_term_load($node->field_artwork_reference['und'][0]['node']->field_medium['und'][0]['tid']);
				?>
            <div id="artwork-reference">
            	<h2><a class="arrow right" href="/<?php print drupal_get_path_alias('node/'.$node->field_artwork_reference['und'][0]['nid']); ?>"><?php print $node->field_artwork_reference['und'][0]['node']->title; ?></a></h2>
                <p class="specs"><?php print $project->name.', 
				'.date('Y', strtotime($node->field_artwork_reference['und'][0]['node']->field_date['und'][0]['value'])).', 
				'.$node->field_artwork_reference['und'][0]['node']->field_materials['und'][0]['value'].', 
				'.$node->field_artwork_reference['und'][0]['node']->field_dimensions['und'][0]['value'].', 
				'.$medium->name; ?></p>
            </div>
            <?php endif; ?>
            
		</div>
        </aside>
	  <?php endif; ?>
      
      <div id="page-content" class="transition">
      	
        <?php
		if(isset($node) && $node->nid == 33):?>
					
			<div id="project-info" class="transition">
				<div id="project-info-toggle" class="toggle transition">
					<a class="open" href="#"><span class="read-about">Read about</span> '<span class="project-title"></span>'</a>
				</div>
				<div id="project-info-description" >
                	<h2></h2>
                    <div class="load"></div>
                </div>
			</div>	  
					  
		<?php endif; ?>
        
        <div id="node-content">
			<?php print render($page['content']); ?>
        </div>
      </div>
    
    </div>
    </div>

  </div>
  
  <div id="overlay" class="transition">
  	<?php
    	if($is_front){
			$block = module_invoke('views', 'block_view', 'home_slideshow-block');
            print render($block);
		}
	?>
  </div>

  <?php print render($page['footer']); ?>
  
</div>



