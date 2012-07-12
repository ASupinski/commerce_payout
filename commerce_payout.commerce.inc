<?php

/**
 * @file
 * Defines commerce integration for the commerce payout.
 */

/*
 Implement hook_commerce_line_item_type_info().
 */
function commerce_payout_commerce_line_item_type_info() {
  $line_item_types['payout_line_item'] = array(
    'type' => 'payout_line_item',
    'name' => t('Payout Line Item'),
    'description' => t('A payout item referenced a line item from which the purchase this payout represents is derived.'),
    'add_form_submit_value' => t('Order Site License'),
    'base' => 'commerce_payout_line_item',
    'product' => FALSE,
  );

  return $line_item_types;
}

/**
 * Returns an appropriate title for this line item.
 */
function commerce_payout_line_item_title($line_item) {
  if ($referenced_line_item = commerce_payout_line_item_get_referenced_line_item($line_item)) {
    return l(commerce_line_item_title($referenced_line_item), 'admin/commerce/orders/' . $referenced_line_item->order_id);
  }
}

/**
 * Returns the elements necessary to add a product line item through a line item
 *   manager widget.
 */
function commerce_payout_line_item_add_form() {
  $form = array();

  $form['line_item_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Line Item ID'),
  );

  return $form;
}

/**
 * Adds the selected product information to a line item added via a line item
 *   manager widget.
 *
 * @param $line_item
 *   The newly created line item object.
 * @param $element
 *   The array representing the widget form element.
 * @param $form_state
 *   The present state of the form upon the latest submission.
 * @param $form
 *   The actual form array.
 *
 * @return
 *   NULL if all is well or an error message if something goes wrong.
 */
function commerce_payout_line_item_add_form_submit(&$line_item, $element, &$form_state, $form) {
  // Load the selected product.
  $referenced_line_item = commerce_line_item_load($element['actions']['line_item_id']['#value']);

  // Populate the line item with the product data.
  commerce_payout_add_line_item_reference($line_item, $referenced_line_item);
}

/**
 * Ensures the product line item type contains a product reference field.
 *
 * This function is called by the line item module when it is enabled or this
 * module is enabled. It invokes this function using the configuration_callback
 * as specified above.
 */
function commerce_payout_line_item_configuration() {
  // Look for or add a display path textfield to the product line item type.
  $field_name = 'commerce_display_path';
  $field = field_info_field($field_name);
  $instance = field_info_instance('commerce_line_item', $field_name, 'payout_line_item');

  if (empty($field)) {
    $field = array(
      'field_name' => $field_name,
      'type' => 'text',
      'cardinality' => 1,
      'entity_types' => array('commerce_line_item'),
      'translatable' => FALSE,
      'locked' => TRUE,
    );
    $field = field_create_field($field);
  }

  if (empty($instance)) {
    $instance = array(
      'field_name' => $field_name,
      'entity_type' => 'commerce_line_item',
      'bundle' => 'payout_line_item',
      'label' => t('Display path'),
      'required' => TRUE,
      'settings' => array(),

      'widget' => array(
        'type' => 'text_textfield',
      ),

      'display' => array(
        'display' => array(
          'label' => 'hidden',
        ),
      ),
    );
    field_create_instance($instance);
  }

  $field_name = 'commerce_payout_line_item';
  $field = field_info_field($field_name);
  $instance = field_info_instance('commerce_line_item', $field_name, 'payout_line_item');

  if (empty($field)) {
    $field = array(
      'field_name' => $field_name,
      'type' => 'commerce_line_item_reference',
      'cardinality' => 1,
      'entity_types' => array(),
      'translatable' => FALSE,
      'locked' => FALSE,
    );
    $field = field_create_field($field);
  }

  if (empty($instance)) {
    $instance = array(
      'field_name' => $field_name,
      'entity_type' => 'commerce_line_item',
      'bundle' => 'payout_line_item',
      'label' => t('Referenced Line Item'),
      'required' => TRUE,
      'settings' => array(),

      'widget' => array(
        'type' => 'text_textfield',
      ),
    );
    field_create_instance($instance);
  }
}

/**
 * Implements hook_commerce_price_component_type_info().
 */
function commerce_payout_commerce_price_component_type_info() {
  return array(
    'gross_sales' => array(
      'title' => t('Gross Sales'),
      'weight' => -10,
    )
  );
}
