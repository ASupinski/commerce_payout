<?php

/**
 * @file
 * Defines rules integration for the commerce payout.
 */

/**
 * Implements hook_rules_event_info().
 */
function commerce_payout_rules_event_info() {
  $events = array();

  //untill http://drupal.org/node/1153766 is handled we can't do this in rules
  /* $events['commerce_payout_calc_pay_date'] = array(
    'label' => t('Calculate the pay date for the creation of a Payout item.'),
    'group' => t('Commerce Payout'),
    'variables' => array(
      'payout' => array(
        'type' => 'commerce_order',
        'label' => t('The payout to set the pay date on.'),
        'skip save' => TRUE,
      ),
      'payee' => array(
        'type' => 'user',
        'label' => t('The user who is the payee of the payout being created.'),
        'skip save' => TRUE,
      ),
      'originating_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('The line item which is causing the generation of the payout.'),
        'skip save' => TRUE,
      ),
      'originating_order' => array(
        'type' => 'commerce_order',
        'label' => t('The order which was just completed, which contains the original_line_item.'),
        'skip save' => TRUE,
      ),
    ),
    'access callback' => 'commerce_order_rules_access',
  );*/

  $events['commerce_payout_calculate_payout_price'] = array(
    'label' => t('Calculating the payout price.'),
    'group' => t('Commerce Payout'),
    'variables' => array(
      'originating_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('The line item which is causing the generation of the payout.'),
        'skip save' => TRUE,
      ),
      'originating_order' => array(
        'type' => 'commerce_order',
        'label' => t('The order which was just completed, which contains the original_line_item.'),
        'skip save' => TRUE,
      ),
      'commerce_line_item' => array(
        'label' => t('Payout line item'),
        'type' => 'commerce_line_item',
        'skip save' => TRUE,
      ),
      'commerce_line_item_unchanged' => array(
        'label' => t('Unchanged payout line item'),
        'type' => 'commerce_line_item',
        'handler' => 'rules_events_entity_unchanged',
        'skip save' => TRUE,
      ),
    ),
    'access callback' => 'commerce_order_rules_access',
  );

  return $events;
}

/**
 * Implements hook_rules_condition_info().
 */
function commerce_payout_rules_condition_info() {
  $items = array();

  $items['commerce_payout_line_item_product_owner'] = array(
    'label' => t('User is the owner of Line Item Product'),
    'base' => 'commerce_payout_line_item_product_owner',
    'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line Item'),
          'description' => t('The Line Item whos Product will be checked to match the specified user'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('The User who will be checked to match the Line Item Product owner'),
        ),
    ),
    'group' => t('Commerce Payout'),
    'access callback' => 'rules_node_integration_access',
  );

  return $items;
}

/**
 * Implements hook_rules_action_info().
 */
function commerce_payout_rules_action_info() {
  $actions = array();

  $actions['commerce_payout_create_payout'] = array(
    'label' => t('Create a payout for a given line item.'),
    'parameter' => array(
      'line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line Item'),
      ),
      'Payee' => array(
        'type' => 'user',
        'label' => t('Payee'),
      ),
    ),
    'provides' => array(
      'payout_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('commerce payout line item'),
      ),
      'payout' => array(
        'type' => 'commerce_order',
        'label' => t('commerce payout.'),
      ),
    ),
    'group' => t('Commerce Payout'),
    'callbacks' => array(
      'execute' => 'commerce_payout_create_payout',
    ),
  );

  $actions['commerce_payout_split'] = array(
    'label' => t('Split Payout'),
    'parameter' => array(
      'payout_line_item' => array(
        'type' => 'commerce_line_item',
        'bundle' => 'payout_line_item',
        'label' => t('Line item'),
      ),
      'amount' => array(
        'type' => 'decimal',
        'label' => t('Amount'),
        'description' => t('amount to be removed from specified payout item and set to new payout item'),
      ),
      'payee' => array(
        'type' => 'user',
        'label' => t('Payee of new payout'),
      ),
      'component_name' => array(
        'type' => 'text',
        'label' => t('Price component type'),
        'description' => t('Price components track changes to prices made during the price calculation process, and they are carried over from the unit price to the total price of a line item. When an order total is calculated, it combines all the components of every line item on the order. When the unit price is altered by this action, the selected type of price component will be added to its data array and reflected in the order total display when it is formatted with components showing. Defaults to base price, which displays as the order Subtotal.'),
        'options list' => 'commerce_payout_commerce_line_item_bootstrap',
        'default value' => 'base_price',
      ),
    ),
    'provides' => array(
      'payout_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('commerce payout line item'),
      ),
      'payout' => array(
        'type' => 'commerce_order',
        'label' => t('commerce payout.'),
      ),
    ),
    'group' => t('Commerce Payout'),
    'callbacks' => array(
      'execute' => 'commerce_payout_split',
    )
  );

  return $actions;
}

function commerce_payout_commerce_line_item_bootstrap() {
  require_once(drupal_get_path('module', 'commerce_line_item') . '/commerce_line_item.rules.inc');
  return commerce_line_item_price_component_options_list();
}


function commerce_payout_default_rules_configuration() {
  $items = array();

  $rule = rule(array(
    'line_item' => array(
     'label' => t('line item'),
     'type' => 'commerce_line_item'
      ),
    'payout_line_item' => array(
     'label' => t('payout line item'),
     'type' => 'commerce_line_item',
     'parameter' => FALSE
    ),
    'payout' => array(
     'label' => 'payout',
     'type' => 'commerce_order',
     'parameter' => FALSE
    )
    ),
    array(
      'payout_line_item',
      'payout'
    )
  );

  $rule->label = t('Create Payout to Product owner');
  $rule->active = TRUE;
  $rule->condition('entity_has_field',
                    array('entity:select' => 'line-item',
                        'field' => 'commerce_product'
                        ))
  ->action('entity_fetch',
                  array(
                    'type' => 'commerce_product',
                    'id:select' => 'line-item:commerce-product:product-id',
                    'entity_fetched:var' => 'product'
                  )
                  )
  ->action('commerce_payout_create_payout',
                  array(
                    'line_item:select' => 'line_item',
                    'Payee:select' => 'product:creator',
                    'payout_line_item:var' => 'payout_line_item2',
                    'payout:var' => 'payout2'
                  )
                  )
  ->action('data_set', array('data:select' => 'payout-line-item', 'value:select' => 'payout-line-item2'))
  ->action('data_set', array('data:select' => 'payout', 'value:select' => 'payout2'));
  $items['rules_create_payout_to_product_owner'] = $rule;
  
  $rule = rules_reaction_rule();
  $rule->label = t('Create Payouts for Paid Orders');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
  ->condition('data_is',
                    array('data:select' => 'commerce-order:status',
                        'value' => 'completed'
                        ))
  ->condition(rules_condition('data_is',
              array('data:select' => 'commerce-order-unchanged:status',
                   'value' => 'completed'
                    ))->negate());
  $loop = rules_loop(array(
    'list:select' => 'commerce-order:commerce-line-items',
    'item:var' => 'line_item',
    'item:label' => t('Current line item'),
    'item:type' => 'commerce_line_item',
  ))
  ->action('component_rules_create_payout_to_product_owner', array(
              'line_item:select' => 'line_item',
              'payout_line_item:var' => 'payout_line_item',
              'payout:var' => 'payout')
            );
  $rule->action($loop);

  $items['rules_create_payouts_for_paid_orders'] = $rule;

  $rule = rules_reaction_rule();
  $rule->label = t('Remove Payouts for un-completed orders');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
  ->condition('data_is',
                    array('data:select' => 'commerce-order-unchanged:status',
                        'value' => 'completed'
                        ))
  ->condition(rules_condition('data_is',
              array('data:select' => 'commerce-order:status',
                   'value' => 'completed'
                    ))->negate());
  $loop = rules_loop(array(
    'list:select' => 'commerce-order:commerce-line-items',
    'item:var' => 'line_item',
    'item:label' => t('Current line item'),
    'item:type' => 'commerce_line_item',
  ))
  ->action('entity_query', array(
              'type' => 'commerce_line_item',
              'property' => 'commerce_payout_line_item',
              'value:select' => 'line-item:line-item-id',
              'limit' => '1',
              'entity_fetched:var' => 'payout_line_item')
            )
  ->action('entity_delete', array('data:select' => 'payout-line-item:0'));
  $rule->action($loop);

  $items['rules_remove_payouts_for_un_completed_orders'] = $rule;
  return $items;
}

function commerce_payout_split($payout_line_item, $amount, $payee, $component) {
  $referenced_line_item = commerce_payout_line_item_get_referenced_line_item($payout_line_item);
  commerce_line_item_unit_price_subtract($payout_line_item, $amount, $component, COMMERCE_ROUND_HALF_UP);
  return commerce_payout_create_payout($referenced_line_item, $payee, $amount, $component);
}

function commerce_payout_line_item_product_owner($line_item, $user) {
  $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
  if (empty($line_item_wrapper->commerce_product)) {
    return FALSE;
  }
  $product = $line_item_wrapper->commerce_product->value();
  return $product->uid == $user->uid;
}
