<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>

<div class="flexslider">
    <ul class="slides">
    <?php foreach($node->field_images['und'] as &$img): ?>
        <li style="background-image:url(<?php print file_create_url($img['uri']); ?>)" ></li>
    <?php endforeach; ?>
    </ul>
</div>


