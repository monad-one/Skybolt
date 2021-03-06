/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "SkyboltVis/SkyboltVisFwd.h"

#include <nlohmann/json.hpp>
#include <boost/optional.hpp>
#include <string>

namespace skybolt {
namespace vis {

struct JsonTileSourceFactoryConfig
{
	std::string cacheDirectory;
	std::map<std::string, std::string> apiKeys;
};

class JsonTileSourceFactory
{
public:
	JsonTileSourceFactory(const JsonTileSourceFactoryConfig& config);

	TileSourcePtr createTileSourceFromJson(const nlohmann::json& json) const;

private:
	std::string getApiKey(const std::string& name) const;

private:
	std::string mCacheDirectory;
	std::map<std::string, std::string> mApiKeys;
};

} // namespace vis
} // namespace skybolt
