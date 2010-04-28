<?php
// $Id$

/**
 * @file
 * Support for paths in core Drupal objects
 */

class MigratePathEntityHandler extends MigrateHandler {
   public function prepare(Migration $migration, stdClass $entity, stdClass $row) {
     if (isset($entity->path_alias)) {
       $entity->path = array();
       $entity->path['alias'] = $entity->path_alias;
       unset($entity->path_alias);
     }
   }
}