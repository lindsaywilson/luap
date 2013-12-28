<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>

  <?php
  if(($view->name == 'images' && $view->current_display == 'images') 
  || $view->name == 'instagrams' 
  || $view->name == 'portfolio' 
  || ($view->name == 'news' && $view->current_display == 'press' )){
  	$classes_array[$id] .= ' thumb';
  }
  $classes_array[$id] .= ' clearfix';
  ?>

  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .' "';  } ?>>
    <div class="inner">
		<?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>