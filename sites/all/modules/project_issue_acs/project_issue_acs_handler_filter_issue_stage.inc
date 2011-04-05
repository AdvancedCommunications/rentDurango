<?php
/**
 * Filter issues based on their stage.
 */
class project_issue_acs_handler_filter_issue_stage extends views_handler_filter_in_operator {

  // Get values for checkbox
 function get_value_options() {
    list($r, $h) =   project_issue_acs_stage_get_allowed_values();
    foreach ($r as $value) {
      $this->value_options[] = $value[2];
    }
  }
 /**
  * Generate the query based on this filter.
  */
  function query() {
    $values = array();
    foreach ($this->value as $key => $value) {
      $values[$key] = $value;
    }
    $this->value = $values;
    parent::query();
  }
}