#include "litan_c_api.h"
#include <map>
#include <cstdint>
#include <SFML/Graphics.hpp>

namespace {
	std::map<std::int64_t, std::unique_ptr<sf::RenderWindow>> windows;
	std::uint64_t next_id = 1;
}


extern "C" {
	void sf_window_open(CApi * api) {
		auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode{1920, 1080}, "Test");
		windows.emplace(next_id, std::move(window));
		api->return_int(next_id++, api->core);
	}
	
	
	
	void sf_window_is_open(CApi * api) {
		const auto id = api->param_int(0, api->core);
		api->return_bool(windows.at(id)->isOpen(), api->core);
	}



	void sf_window_destroy(CApi * api) {
		const auto id = api->param_int(0, api->core);
		windows.erase(id);
	}



	void sf_window_clear(CApi * api) {
		const auto id = api->param_int(0, api->core);
		const auto color = api->param_int(1, api->core);
		windows.at(id)->clear(sf::Color{static_cast<std::uint32_t>(color)});
	}



	void sf_window_display(CApi * api) {
		const auto id = api->param_int(0, api->core);
		windows.at(id)->display();
	}
}