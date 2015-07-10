<?php

/**
 * Implements hook_drush_command()
 */
function mymodule_drush_command() {
  $items['maintenance'] = array(
    'description' => "Sets maintenance mode and message",
    'aliases' => array('mm'), // warning the conflicts with migrate module see http://drushcommands.com/

    'arguments' => array(
      'state' => "The state of maintance mode you want (on|off)",
    ),

    'options' => array(
      'message' => "The message to display in maintenance mode",
    ),

    'examples' => array(
      'drush mm on' => "Turns on maintenance mode with the last message",
      'drush mm on --message="This is my message' => "turn on maintenance mode with message 'This is my message'",
    ),
  );

  return $items;
}

function drush_mymodule_maintenance($state = "on") {
  $message = drush_get_option('message');

  if($state == "on") {
    variable_set("maintenance_mode", 1);

    if(!empty($message)) {
      variable_set("maintenance_mode_message", $message);
    }

    echo "On with '" . variable_get("maintenance_mode_message") . "'\n";

  }

  elseif($state == "off") {
    variable_set("maintenance_mode", 0);
    echo "Off\n";
  }

  else {
    echo "WAT?\n";
  }



}
