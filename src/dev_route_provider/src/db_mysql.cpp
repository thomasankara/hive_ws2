#include "dev_route_provider/db_mysql.hpp"
#include <stdexcept>
#include <sstream>
#include <cstdlib>

namespace dev_route_provider {

bool DBMySQL::connect(std::string& err) {
  disconnect();
  conn_ = mysql_init(nullptr);
  if(!conn_) { err = "mysql_init failed"; return false; }

  unsigned int to = 5;
  mysql_options(conn_, MYSQL_OPT_CONNECT_TIMEOUT, &to);
  mysql_options(conn_, MYSQL_OPT_READ_TIMEOUT, &to);
  mysql_options(conn_, MYSQL_OPT_WRITE_TIMEOUT, &to);

  if(!mysql_real_connect(conn_, host_.c_str(), user_.c_str(), password_.c_str(),
                         dbname_.c_str(), port_, nullptr, 0)) {
    err = mysql_error(conn_);
    disconnect();
    return false;
  }
  mysql_set_character_set(conn_, "utf8mb4");
  return true;
}

void DBMySQL::disconnect() {
  if(conn_) { mysql_close(conn_); conn_ = nullptr; }
}

std::string DBMySQL::escape(const std::string& s) {
  if(!conn_) return s;
  std::string out;
  out.resize(s.size() * 2 + 1);
  unsigned long len = mysql_real_escape_string(conn_, &out[0], s.c_str(), s.size());
  out.resize(len);
  return out;
}

bool DBMySQL::fetch_lanelets(const DBFilter& f,
                             std::vector<hive_interface2::msg::LaneletMini2>& out,
                             std::string& err) {
  if(!conn_) { err = "Not connected"; return false; }
  out.clear();

  // build safe query for table lanelet_mini (NOT lanelet_mini2)
  const std::string e = escape(f.enterprise_full_id_str);
  const std::string d = escape(f.deployment_full_id_str);
  const std::string s = escape(f.slam_session_full_id_str);

  std::ostringstream q;
  q << "SELECT "
       "enterprise_full_id_str,"
       "deployment_full_id_str,"
       "slam_session_full_id_str,"
       "lanelet_mini_id,"
       "start_point_x,start_point_y,start_point_z,"
       "end_point_x,end_point_y,end_point_z,"
       "navigation_direction,border_mode,"
       "u_turn_allowed,slope_alert,vegetation_alert,offroad_alert,"
       "configuration_group_id_str,road_group_id_str,"
       "max_speed,width "
     "FROM lanelet_mini "
     "WHERE enterprise_full_id_str='" << e << "' "
     "AND deployment_full_id_str='" << d << "' "
     "AND slam_session_full_id_str='" << s << "' "
     "ORDER BY lanelet_mini_id;";

  if(mysql_query(conn_, q.str().c_str()) != 0) {
    err = mysql_error(conn_);
    return false;
  }
  MYSQL_RES* res = mysql_store_result(conn_);
  if(!res) { err = mysql_error(conn_); return false; }

  MYSQL_ROW row;
  unsigned long n = mysql_num_rows(res);
  out.reserve(n);

  while((row = mysql_fetch_row(res))) {
    int idx = 0;
    hive_interface2::msg::LaneletMini2 m;

    m.enterprise_full_id_str = row[idx++] ? row[idx-1] : "";
    m.deployment_full_id_str = row[idx++] ? row[idx-1] : "";
    m.slam_session_full_id_str = row[idx++] ? row[idx-1] : "";

    m.lanelet_mini_id = row[idx++] ? static_cast<int32_t>(std::strtol(row[idx-1], nullptr, 10)) : 0;

    m.start_point_x = row[idx++] ? static_cast<float>(std::strtof(row[idx-1], nullptr)) : 0.f;
    m.start_point_y = row[idx++] ? static_cast<float>(std::strtof(row[idx-1], nullptr)) : 0.f;
    idx++; 
    m.start_point_z = 0.0f;

    m.end_point_x = row[idx++] ? static_cast<float>(std::strtof(row[idx-1], nullptr)) : 0.f;
    m.end_point_y = row[idx++] ? static_cast<float>(std::strtof(row[idx-1], nullptr)) : 0.f;
    idx++; 
    m.end_point_z = 0.0f;

    m.navigation_direction = row[idx++] ? static_cast<int32_t>(std::strtol(row[idx-1], nullptr, 10)) : 0;
    m.border_mode          = row[idx++] ? static_cast<int32_t>(std::strtol(row[idx-1], nullptr, 10)) : 0;

    auto as_bool = [](const char* c)->bool { return c && std::strtol(c, nullptr, 10) != 0; };
    m.u_turn_allowed   = as_bool(row[idx++]);
    m.slope_alert      = as_bool(row[idx++]);
    m.vegetation_alert = as_bool(row[idx++]);
    m.offroad_alert    = as_bool(row[idx++]);

    m.configuration_group_id_str = row[idx++] ? row[idx-1] : "";
    m.road_group_id_str          = row[idx++] ? row[idx-1] : "";

    m.max_speed = row[idx++] ? static_cast<int32_t>(std::strtol(row[idx-1], nullptr, 10)) : 0;
    m.width     = row[idx++] ? static_cast<float>(std::strtof(row[idx-1], nullptr)) : 0.f;

    out.push_back(std::move(m));
  }
  mysql_free_result(res);
  return !out.empty();
}

} // namespace dev_route_provider
