#pragma once

#include <boost/variant/static_visitor.hpp>

#include "mstch/mstch.hpp"

namespace mstch {

class has_token: public boost::static_visitor<bool> {
 public:
  has_token(const std::string& token): token(token) {
  }

  template<class T>
  inline bool operator()(const T& t) const {
    return token == ".";
  }

  bool operator()(const map& map) const {
    return map.count(token) == 1;
  }

  bool operator()(const std::shared_ptr<object>& object) const {
    return object->has(token);
  }

 private:
  const std::string& token;
};

}
