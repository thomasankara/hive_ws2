#pragma once
#include <mutex>
#include <vector>
#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_interface2/msg/poi.hpp"
#include "hive_interface2/msg/free_zone.hpp"
#include "hive_interface2/msg/nav_brain_command.hpp"

class DataStore {
public:
  void set_lanelets(std::vector<hive_interface2::msg::LaneletMini2> v) {
    std::lock_guard<std::mutex> lk(m_);
    lanelets_ = std::move(v);
    got_lanelets_ = true;
  }
  void set_pois(std::vector<hive_interface2::msg::Poi> v) {
    std::lock_guard<std::mutex> lk(m_);
    pois_ = std::move(v);
    got_pois_ = true;
  }
  void set_freezones(std::vector<hive_interface2::msg::FreeZone> v) {
    std::lock_guard<std::mutex> lk(m_);
    free_zones_ = std::move(v);
    got_free_zones_ = true;
  }
  void set_last_cmd(const hive_interface2::msg::NavBrainCommand& c) {
    std::lock_guard<std::mutex> lk(m_); last_cmd_ = c;
  }

  bool has_lanelets()    const { return got_lanelets_; }
  bool has_pois()        const { return got_pois_; }
  bool has_free_zones()  const { return got_free_zones_; }

  // (accès lecture si besoin plus tard)
private:
  mutable std::mutex m_;
  std::vector<hive_interface2::msg::LaneletMini2> lanelets_;
  std::vector<hive_interface2::msg::Poi>          pois_;
  std::vector<hive_interface2::msg::FreeZone>     free_zones_;
  hive_interface2::msg::NavBrainCommand           last_cmd_;
  bool got_lanelets_{false}, got_pois_{false}, got_free_zones_{false};
};
