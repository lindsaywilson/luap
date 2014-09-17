<?php
/**
 * @file
 * portfolio_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function portfolio_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'portfolio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'views-field-edit-node';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Medium */
  $handler->display->display_options['fields']['field_medium']['id'] = 'field_medium';
  $handler->display->display_options['fields']['field_medium']['table'] = 'field_data_field_medium';
  $handler->display->display_options['fields']['field_medium']['field'] = 'field_medium';
  $handler->display->display_options['fields']['field_medium']['label'] = '';
  $handler->display->display_options['fields']['field_medium']['element_type'] = '0';
  $handler->display->display_options['fields']['field_medium']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_medium']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project']['id'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['table'] = 'field_data_field_project';
  $handler->display->display_options['fields']['field_project']['field'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['label'] = '';
  $handler->display->display_options['fields']['field_project']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '<div class="[field_medium] ">
[field_image]
</div>';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'thumb',
    'image_link' => '',
  );
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'artwork' => 'artwork',
  );

  /* Display: All */
  $handler = $view->new_display('block', 'All', 'all');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'artwork' => 'artwork',
  );
  /* Filter criterion: Content: Medium (field_medium) */
  $handler->display->display_options['filters']['field_medium_tid']['id'] = 'field_medium_tid';
  $handler->display->display_options['filters']['field_medium_tid']['table'] = 'field_data_field_medium';
  $handler->display->display_options['filters']['field_medium_tid']['field'] = 'field_medium_tid';
  $handler->display->display_options['filters']['field_medium_tid']['value'] = array(
    9 => '9',
    10 => '10',
    11 => '11',
    12 => '12',
    13 => '13',
    14 => '14',
    15 => '15',
    16 => '16',
  );
  $handler->display->display_options['filters']['field_medium_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_medium_tid']['vocabulary'] = 'medium';

  /* Display: Disciplines */
  $handler = $view->new_display('page', 'Disciplines', 'disciplines');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'project';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'project' => 'project',
    'exhibition_type' => 0,
    'image_gallery' => 0,
    'medium' => 0,
    'news_type' => 0,
    'sub_project' => 0,
    'tags' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Medium (field_medium) */
  $handler->display->display_options['arguments']['field_medium_tid']['id'] = 'field_medium_tid';
  $handler->display->display_options['arguments']['field_medium_tid']['table'] = 'field_data_field_medium';
  $handler->display->display_options['arguments']['field_medium_tid']['field'] = 'field_medium_tid';
  $handler->display->display_options['arguments']['field_medium_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_medium_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_medium_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_medium_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_medium_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_medium_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_medium_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_medium_tid']['validate_options']['vocabularies'] = array(
    'medium' => 'medium',
  );
  $handler->display->display_options['arguments']['field_medium_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_medium_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['path'] = 'disciplines/%';

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'projects');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'sub project';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'sub_project' => 'sub_project',
    'exhibition_type' => 0,
    'image_gallery' => 0,
    'medium' => 0,
    'news_type' => 0,
    'project' => 0,
    'tags' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project) */
  $handler->display->display_options['arguments']['field_project_tid']['id'] = 'field_project_tid';
  $handler->display->display_options['arguments']['field_project_tid']['table'] = 'field_data_field_project';
  $handler->display->display_options['arguments']['field_project_tid']['field'] = 'field_project_tid';
  $handler->display->display_options['arguments']['field_project_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_project_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_project_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_project_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_project_tid']['validate_options']['vocabularies'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['arguments']['field_project_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_project_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['path'] = 'projects/%';

  /* Display: Latest */
  $handler = $view->new_display('page', 'Latest', 'latest');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'portfolio/latest';

  /* Display: Highlighted */
  $handler = $view->new_display('page', 'Highlighted', 'highlighted');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'artwork' => 'artwork',
  );
  /* Filter criterion: Content: Include in highlighted list (field_highlighted) */
  $handler->display->display_options['filters']['field_highlighted_value']['id'] = 'field_highlighted_value';
  $handler->display->display_options['filters']['field_highlighted_value']['table'] = 'field_data_field_highlighted';
  $handler->display->display_options['filters']['field_highlighted_value']['field'] = 'field_highlighted_value';
  $handler->display->display_options['filters']['field_highlighted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'portfolio/highlighted';
  $export['portfolio'] = $view;

  return $export;
}
