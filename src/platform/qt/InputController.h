#ifndef QGBA_INPUT_CONTROLLER_H
#define QGBA_INPUT_CONTROLLER_H

extern "C" {
#include "gba-input.h"

#ifdef BUILD_SDL
#include "platform/sdl/sdl-events.h"
#endif
}

namespace QGBA {

class ConfigController;

class InputController {
public:
	static const uint32_t KEYBOARD = 0x51545F4B;

	InputController();
	~InputController();

	void setConfiguration(ConfigController* config);
	void loadConfiguration(uint32_t type);
	void saveConfiguration(uint32_t type = KEYBOARD);

	GBAKey mapKeyboard(int key) const;

	void bindKey(uint32_t type, int key, GBAKey);

	const GBAInputMap* map() const { return &m_inputMap; }

#ifdef BUILD_SDL
	int testSDLEvents();
#endif

private:
	GBAInputMap m_inputMap;
	ConfigController* m_config;

#ifdef BUILD_SDL
	GBASDLEvents m_sdlEvents;
#endif
};

}

#endif
