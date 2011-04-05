<?php
/*
 * Implementation of hook_project_issue_metadata
 * Adds stage to project issue node view
 *
 * TODO: DAL 1/15/11 NOT currently functioning, not activated by hook, FIX
 * TODO: hard coded replacement in project_issues/issue_node_view.inc:_project_issue_view
 */
function project_issue_acs_project_issue_metadata($view,$node,$current_data) {
 $current_data['stage'] = array(
      'label' => t('Stage'),
      'current' => project_issue_acs_stage_value(project_issue_acs_stage_record($node->nid)),
    );
}
