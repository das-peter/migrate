<?php
// $Id: path.inc,v 1.1.2.4 2010/07/03 16:56:41 mikeryan Exp $

/**
 * @file
 * Support for paths in core Drupal objects
 */

class MigratePathEntityHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('entity'));
  }

  public function fields() {
    return array('path' => t('Node: Path alias'));
  }

  public function prepare(Migration $migration, stdClass $entity, stdClass $row) {
    if (isset($entity->path)) {
      $path = $entity->path;
      $entity->path = array();
      $entity->path['alias'] = $path;
    }
  }
}
