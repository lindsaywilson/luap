<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 //dpm($fields);
 
 //preg_match( '/src="([^"]*)"/i', $foo, $array ) ;
 
?>
<?php foreach ($fields as $id => $field): ?>

<?php
	
	switch($field->class){
		
		case 'link':
		case 'caption':
		case 'likes':
		break;
		
		case 'images':
			preg_match( '/src="([^"]*)"/i', $field->content, $src);
			$caption = '';
			if (isset($fields['caption'])) {
				$caption = $fields['caption']->content;
			}
			print '<a href="'.$fields['link']->content.'" target="_blank" title="'.$caption.'"><img class="lazy" data-src="'.$src[1].'" src="/'.path_to_theme().'/images/pixel.gif" /><div class="transition likes">Likes <span>'.$fields['likes']->content.'</span></div></a>';
		break;
		
		default:
			print $field->content;
		break;
		
	}
	
?>

<?php endforeach; ?>