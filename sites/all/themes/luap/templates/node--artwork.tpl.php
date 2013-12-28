<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
 
 $term = taxonomy_term_load($content['field_project']['#items'][0]['tid']);

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  
	<div id="artwork-image">
		<?php print render($content['field_image']); ?>
	</div>
	
    <div id="artwork-info-bar" class="info-bar">
    <div class="inner clearfix">
        <div id="share">
        	<?php include_once DRUPAL_ROOT . '/' . path_to_theme() . '/templates/include--share.inc'; ?>
        </div>
        <a href="#" id="read-about" class="arrow down">Read about '<?php print $term->name ?>'</a>
    </div>
    </div>
    
    <div id="artwork-details">
    	<h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    	<p class="specs">
		<?php
		print $content['field_project'][0]['#title'].', 
			'.$content['field_date'][0]['#markup'].', 
			'.$content['field_materials'][0]['#markup'].', 
			'.$content['field_dimensions'][0]['#markup'].', 
			'.$content['field_medium'][0]['#title']; ?>
        </p>
    </div>
    
    <div id="artwork-project-details">
    	<h2><?php print $term->name ?></h2>
        <?php print $term->description ?>
    </div>
    
    <div id="artwork-project-bar" class="info-bar">
    <div class="inner clearfix">
    	<a class="arrow" href="/portfolio/#/<?php print str_replace(' ','-', strtolower($term->name)); ?>">View the '<?php print $term->name ?>' project</a>
    </div>
    </div>


</article>

