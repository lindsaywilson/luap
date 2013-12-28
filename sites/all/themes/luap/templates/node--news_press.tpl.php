<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

?>

<?php if($view_mode == 'full'): ?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($content['field_intro']); ?>
    
    <?php print render($content['body']); ?>
    
    <?php print render($content['field_extra_content']); ?>
    
    <div id="news-info-bar" class="info-bar">
    <div class="inner width clearfix">
    	<?php 
		$artwork = node_load($content['field_artwork_reference']['#items'][0]['nid']);
		$project = taxonomy_term_load($artwork->field_project['und'][0]['tid']);
		?>
        <div id="share">
        	<?php include_once DRUPAL_ROOT . '/' . path_to_theme() . '/templates/include--share.inc'; ?>
        </div>
        <a class="arrow" href="/portfolio/#/<?php print strtolower(str_replace(' ','-',$project->name)) ?>">View '<?php print $project->name ?>' project</a>
    </div>
    </div>

</article>

<?php endif; ?>

<?php 
if($view_mode == 'teaser' && $node->field_news_type['und'][0]['tid'] == 22):
	
	global $user;
	$path = image_style_url('full_width', $content['field_image']['#items'][0]['uri']); 
	?>
	
    <div class="full-width" style="background-image:url(<?php print $path; ?>)">
        <div class="info-box">
            <h2><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <?php print render($content['field_intro']); ?>
            <a class="read-more" href="<?php print $node_url; ?>"><?php print $content['field_link_text'][0]['#markup']; ?></a>
        </div>
        <?php if (in_array('administrator', $user->roles)): ?>
          <div class="views-field-edit-node"><a class="edit-node" href="/node/<?php print $nid ?>/edit">Edit</a></div>
		<?php endif; ?>
    </div>

<?php endif; ?>

<?php 
if($view_mode == 'teaser' && $node->field_news_type['und'][0]['tid'] == 23): 
	
	$path = image_style_url('press_logo', $content['field_logo']['#items'][0]['uri']);
	?>
	<a class="press-item" href="<?php print $node_url; ?>" style="background-image:url(<?php print $path; ?>)"><?php print $title; ?></a>	
	<?php if (in_array('administrator', $user->roles)): ?>
	<div class="views-field-edit-node"><a class="edit-node" href="/node/<?php print $nid ?>/edit">Edit</a></div>
	<?php endif; ?>

<?php endif; ?>

