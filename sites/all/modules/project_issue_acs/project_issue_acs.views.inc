<?php
// $Id: project_issue.views.inc,v 1.9 2009/06/18 03:48:53 dww Exp $

/**
 * @file
 * Provides support for Views integration.
 */

/**
 * Implementation of hook_views_data().  Exposes stage custom field to views.
 */
function project_issue_acs_views_data() {
  $data = array();

  $data['project_issue_acs_stage']['table']['group']  = t('Project issue');

  // Define relationship of stage table to node
  $data['project_issue_acs_stage']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // Exposes stage
  $data['project_issue_acs_stage']['value'] = array(
    'title' => t('Stage'),
    'help' => t('The stage of the issue.'),
    // As a field
    'field' => array(
      // Handler converts stage key to text values for display
      'handler' => 'project_issue_acs_handler_field_issue_stage', 
      'click sortable' => TRUE,
    ),
    // as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // as a filter
    'filter' => array(
      // Handler populates stage check box and creates query
      'handler' => 'project_issue_acs_handler_filter_issue_stage', 
    ),
    // as a sort
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 * Defines inheritence relationships for handlers.
 */
function project_issue_acs_views_handlers() {
  return array(
    'handlers' => array(
      'project_issue_acs_handler_filter_issue_stage' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'project_issue_acs_handler_field_issue_stage' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}