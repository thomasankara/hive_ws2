// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2.h"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_H_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'enterprise_full_id_str'
// Member 'deployment_full_id_str'
// Member 'slam_session_full_id_str'
// Member 'configuration_group_id_str'
// Member 'road_group_id_str'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LaneletMini2 in the package hive_interface2.
/**
  * ============================================================
  * Hive Robotics - LaneletMini2.msg
  * ============================================================
  * Représente une portion de voie simplifiée issue de la base SQL lanelet_mini2
  * Utilisée pour la navigation autonome dans Hive Robotics.
  * Chaque champ correspond directement à une colonne SQL.
  * ============================================================
 */
typedef struct hive_interface2__msg__LaneletMini2
{
  /// --- Identifiants hiérarchiques ---
  /// Entreprise associée (nom complet)
  rosidl_runtime_c__String enterprise_full_id_str;
  /// Déploiement associé (nom complet)
  rosidl_runtime_c__String deployment_full_id_str;
  /// Session SLAM associée (nom complet)
  rosidl_runtime_c__String slam_session_full_id_str;
  /// --- Identifiant principal du lanelet ---
  /// ID unique du lanelet_mini
  int32_t lanelet_mini_id;
  /// --- Coordonnées du point de départ (référentiel 'map') ---
  float start_point_x;
  float start_point_y;
  float start_point_z;
  /// --- Coordonnées du point d'arrivée (référentiel 'map') ---
  float end_point_x;
  float end_point_y;
  float end_point_z;
  /// --- Propriétés de navigation ---
  /// 0=fermé | 1=start->end | 2=end->start | 3=bidirectionnel
  int32_t navigation_direction;
  /// 0=aucun | 1=gauche | 2=droite | 3=deux côtés
  int32_t border_mode;
  /// true = demi-tour autorisé
  bool u_turn_allowed;
  /// true = pente significative (précaution requise)
  bool slope_alert;
  /// true = forte végétation (ralentir)
  bool vegetation_alert;
  /// true = zone non-bitumée (terre, gravier, etc.)
  bool offroad_alert;
  /// --- Groupes logiques ---
  /// Sous-groupe de configuration (ex: avenues)
  rosidl_runtime_c__String configuration_group_id_str;
  /// Groupe routier (ex: grande route)
  rosidl_runtime_c__String road_group_id_str;
  /// --- Propriétés physiques ---
  /// Vitesse max (en km/h)
  int32_t max_speed;
  /// Largeur de la route (en mètres)
  float width;
} hive_interface2__msg__LaneletMini2;

// Struct for a sequence of hive_interface2__msg__LaneletMini2.
typedef struct hive_interface2__msg__LaneletMini2__Sequence
{
  hive_interface2__msg__LaneletMini2 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hive_interface2__msg__LaneletMini2__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__STRUCT_H_
