#pragma once
#include <string>

struct HiveNavParams {
  std::string ns{"robot1"};
  std::string fetch_service_basename{"refresh_all_data"}; // ou "get_route_data"
  // Dérivés
  std::string topic_lanelets;
  std::string topic_pois;
  std::string topic_freezones;
  std::string topic_cmd;
  std::string service_name;

  void build_names() {
    topic_lanelets  = "/" + ns + "/route_data";
    topic_pois      = "/" + ns + "/poi_data";
    topic_freezones = "/" + ns + "/free_zone_data";
    topic_cmd       = "/" + ns + "/nav_brain/command";
    service_name    = "/" + ns + "/" + fetch_service_basename;
  }
};
