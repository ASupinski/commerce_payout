<?php
/**
 * @file
 * Defines default views for the commerce payout.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_payout_views_default_views() {
  $views = array();
  
  $view = new view;
    $view->name = 'payouts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Payouts';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Payouts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'admin';
  /* Field: Commerce Order: commerce_payout_pay_date */
  $handler->display->display_options['fields']['commerce_payout_pay_date']['id'] = 'commerce_payout_pay_date';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['table'] = 'field_data_commerce_payout_pay_date';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['field'] = 'commerce_payout_pay_date';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['label'] = 'Expected Payout Date';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['type'] = 'date_long';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['commerce_payout_pay_date']['group_rows'] = 1;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['delta_offset'] = '0';
  $handler->display->display_options['fields']['commerce_payout_pay_date']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['commerce_payout_pay_date']['field_api_classes'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_formatted_components';
  $handler->display->display_options['fields']['commerce_order_total']['field_api_classes'] = 0;
  /* Sort criterion: Commerce Order: commerce_payout_pay_date (commerce_payout_pay_date) */
  $handler->display->display_options['sorts']['commerce_payout_pay_date_value']['id'] = 'commerce_payout_pay_date_value';
  $handler->display->display_options['sorts']['commerce_payout_pay_date_value']['table'] = 'field_data_commerce_payout_pay_date';
  $handler->display->display_options['sorts']['commerce_payout_pay_date_value']['field'] = 'commerce_payout_pay_date_value';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_payout' => 'commerce_payout',
  );
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'pending' => 'pending',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['state']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['state']['expose']['reduce'] = 1;

  /* Display: Payouts */
  $handler = $view->new_display('page', 'Payouts', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/payouts/list';
  $translatables['payouts'] = array(
    t('Master'),
    t('Payouts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Order owner'),
    t('Order ID'),
    t('Expected Payout Date'),
    t('E-mail'),
    t('Name'),
    t('Order total'),
    t('Order state'),
  );
  $views['payouts'] = $view;
  
  return $views;
}
