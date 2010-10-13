<?php
// $Id: path.inc,v 1.1.2.5 2010/10/09 17:34:33 mikeryan Exp $

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

  public function prepare(stdClass $entity, stdClass $row) {
    if (isset($entity->path)) {
      $path = $entity->path;
      $entity->path = array();
      $entity->path['alias'] = $path;
    }
  }
}
