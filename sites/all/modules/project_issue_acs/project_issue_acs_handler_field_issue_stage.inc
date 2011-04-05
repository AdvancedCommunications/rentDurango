<?php
// $Id: project_issue_handler_field_issue_stage.inc,v 1.2 2009/01/20 18:38:04 dww Exp $


/**
 * Field handler to display the current stage of an issue.  Converts from integer
 * to string
 * (ie. project_issue_acs_stage.value = 1 to project_issue_acs_stage_av.av = "Immediate")
 */
class project_issue_acs_handler_field_issue_stage extends views_handler_field {
  function render($values) {
    $a = $this->field_alias;
    $b=$values->{$this->field_alias};
    return check_plain(project_issue_acs_stage_value($values->{$this->field_alias}));
  }
}

