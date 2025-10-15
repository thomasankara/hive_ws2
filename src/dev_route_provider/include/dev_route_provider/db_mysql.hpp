#pragma once
#include <string>
#include <vector>
#include <mysql.h>
#include "hive_interface2/msg/lanelet_mini2.hpp"

namespace dev_route_provider {

struct DBFilter {
  std::string enterprise_full_id_str;
  std::string deployment_full_id_str;
  std::string slam_session_full_id_str;
};

class DBMySQL {
public:
  DBMySQL(const std::string& host, unsigned port,
          const std::string& user, const std::string& password,
          const std::string& dbname)
  : host_(host), port_(port), user_(user), password_(password), dbname_(dbname) {}

  ~DBMySQL() { disconnect(); }

  bool connect(std::string& err);
  void disconnect();

  bool fetch_lanelets(const DBFilter& f,
                      std::vector<hive_interface2::msg::LaneletMini2>& out,
                      std::string& err);

private:
  std::string host_;
  unsigned    port_;
  std::string user_;
  std::string password_;
  std::string dbname_;

  MYSQL* conn_{nullptr};

  std::string escape(const std::string& s);
};

} // namespace dev_route_provider
