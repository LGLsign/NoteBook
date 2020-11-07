#ifndef FND_JSON_OBJECT_H
#define FND_JSON_OBJECT_H

#ifndef BOOST_BIND_GLOBAL_PLACEHOLDERS
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#endif

#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>

using ptree = boost::property_tree::ptree;

inline std::string ptreeToJsonString(const ptree& tree) {
	std::stringstream ss;
	boost::property_tree::write_json(ss, tree, false);
	return ss.str();
}

#endif
